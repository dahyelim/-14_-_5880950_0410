#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define MAX_DEGREE 100

void multiply_poly(int A[], int degA, int B[], int degB[], int result[]) {
	for (int i = 0; i <= degA + degB; i++) {
		result[i] = 0;
	}

	for (int i = 0; i <= degA; i++) {
		for (int j = 0; j <= degB; j++) {
			result[i + j] += A[j] * B[j];
		}
	}
}

void print_poly(int poly[], int degree) {
	for (int i = degree; i >= 0; i--) {
		if (poly[i] == 0) {
			continue;
		}
		if (i != degree && poly[i] > 0) {
			printf("+");
		}
		if (i == 0) {
			printf("%d", poly[i]);
		}
	}
}
