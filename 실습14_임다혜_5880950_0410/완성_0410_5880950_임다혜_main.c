#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "linearList_5880950_임다혜.h"

void parsePolynomial(char* input, listType* poly) {
    int i = 0, coef = 0, expo = 0, sign = 1;
    while (input[i]) {
        if (input[i] == '+') {
            sign = 1;
            i++;
        }
        else if (input[i] == '-') {
            sign = -1;
            i++;
        }

        coef = 0;
        while (isdigit(input[i])) {
            coef = coef * 10 + (input[i++] - '0');
        }
        if (input[i] == 'x' || input[i] == 'X') {
            i++;
            if (input[i] == '^') {
                i++;
                expo = 0;
                while (isdigit(input[i])) {
                    expo = expo * 10 + (input[i++] - '0');
                }
            }
            else {
                expo = 1;
            }
        }
        else {
            expo = 0;
        }

        elementType term = { sign * (coef == 0 ? 1 : coef), expo };
        ordered_insertItem(poly, term);
    }
}

listType* addPolynomials(listType* a, listType* b) {
    listType* result = createList(20);
    int i = 0, j = 0;

    while (i <= a->last && j <= b->last) {
        elementType t1 = readItem(a, i);
        elementType t2 = readItem(b, j);

        if (t1.expo == t2.expo) {
            elementType sum = { t1.coef + t2.coef, t1.expo };
            if (sum.coef != 0)
                ordered_insertItem(result, sum);
            i++; j++;
        }
        else if (t1.expo < t2.expo) {
            ordered_insertItem(result, t1);
            i++;
        }
        else {
            ordered_insertItem(result, t2);
            j++;
        }
    }

    while (i <= a->last)
        ordered_insertItem(result, readItem(a, i++));
    while (j <= b->last)
        ordered_insertItem(result, readItem(b, j++));

    return result;
}

int main() {
    char input1[100], input2[100];
    printf("첫번째 다항식을 입력하세요(예:3x^2+4x+1): ");
    scanf_s("%s", input1);
    printf("두 번째 다항식을 입력하세요 (예: 2x^2+5x+3): ");
    scanf_s("%s", input2);

    listType* poly1 = createList(20);
    listType* poly2 = createList(20);
    parsePolynomial(input1, poly1);
    parsePolynomial(input2, poly2);

    listType* sum = addPolynomials(poly1, poly2);
    printf("\n[덧셈결과]\n");
    printList(sum);

    listType* prod = multiplyPolynomials(poly1, poly2);
    printf("\n[곱셈 결과]\n");
    printList(prod);

    destroyList(poly1);
    destroyList(poly2);
    destroyList(sum);
    destroyList(prod);

    return 0;
}
