#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "functions.h"
#include "myLib.h"

void displayHelp(char *commands[256]) {
	int i = 0;
	while (commands[i])
		printf("%s\n", commands[i++]);
}

void summations() {
	long int start = 1, end = 1024, increment = 1,
		i = start, total = 0;

	while (i <= end) {
		printf("%ld\n", i);
		i = (long)pow(2, start);
		total += i;
		start += increment;
	}

	printf("Total: %ld\n", total);
}

void binaryTest(int size) {
	int max, countSub = 0, countBinary = 0;
	char *binary;

	max = (1 << size);

	for (int i = 0; i < max; i++) {
		binary = toBinary(i, size);
		puts(binary);

		if (strstr(binary, "001") != NULL)	countSub++;
		if (countOccurences(binary, "0") > 3)	countBinary++;
	}

	printf("%d binary strings of size %d contain the substring \"001\"\n", countSub, size);
	printf("%d binary strings of size %d have at least 4 zeros.\n", countBinary, size);
}

void reverse(char *s) {
	if (s[0] != '\0')
		reverse(&(s[1]));
	printf("%c", s[0]);
}

void runBullshit() {
	int a = 5, b = 7;

	swap(&a, &b);

	printf("%d\t%d\n", a, b);
}
