#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "myLib.h"

int hexToInt(char *sNum) {
	int iNum = 0, iTemp;

	//Check that the value entered is valid
	if (!sNum || strstr(sNum, "x") == NULL) {
		puts("Invalid hexadecimal entered! Returning.");
		return -1;
	}
	else
		sNum += 2;

	// Loop through every char of the string version of the number
	while (*sNum) {
		// current char is a decimal
		if (*sNum >= 48 && *sNum <= 57)
			iTemp = *sNum - 48;
		// Current char is uppercase
		else if (*sNum >= 65 && *sNum <= 70)
			iTemp = *sNum - 55;
		// Current char is lowercase
		else if (*sNum >= 97 && *sNum <= 102)
			iTemp = *sNum - 87;
		else {
			printf("Invalid digit entered!\n");
			return -1;
		}

		if (*++sNum) {
			iTemp *= 16;
			iNum *= 10;
		}

		iNum += iTemp;
	}

	return iNum;
}

char* toBinary(int num, int bits) {
	// If bits == -1, at call time the number of bits needed is unknown so it will be calculated
	if (bits == -1) {
		bits = 1;

		//Continue to increase the bit size by one until the correct range is found
		while (!(num >= power(2, bits-1) && num <= power(2, bits) - 1))
			bits++;
	}

	int index = bits - 1;
	char *binary = malloc(sizeof(char)* bits);

	if (binary == NULL) {
		puts("Malloc failed! returning.");
		return "";
	}

	while (num != 0) {
		binary[index--] = (num % 2) + '0';
		num = num >> 1;
	}

	while (index >= 0)
		binary[index--] = '0';
	binary[bits] = 0;

	return binary;
}

char** split(char *string, char *key) {
	char **parsed = malloc(sizeof(char) * countOccurences(string, key) + 2);
	int count = 0;

	if (parsed == NULL) {
		puts("Malloc failed! returning.");
		strcpy(parsed[0], "error");
		return parsed;
	}

	// Continue splitting until string is all removed
	while (*string != '\0') {
		char temp[500] = "", *a = temp;
		int keyLength = strlen(key);

		// Copy until the end of string, or finding the key will break
		while (*string != '\0') {
			int offset = 0;

			// Check if current start of string matches key
			while(*string != '\0' && string[offset] == key[offset])
				offset++;

			// If key is found, skip the key and break loop in order to save current temp copy
			if (offset == keyLength) {
				string += keyLength;
				break;
			}
			else
				*a++ = *string++;
		}
		*a = 0;

		parsed[count] = malloc(sizeof(char)* strlen(temp) + 1);
		if (parsed[count] == NULL) {
			puts("Malloc failed! returning.");
			strcpy(parsed[0], "error");
			return parsed;
		}

		strcpy(parsed[count++], temp);
	}

	//Set last split to NULL, this can be used for looping through the splits. Loop while index not NULL for example
	parsed[count] = NULL;
	return parsed;
}

char* strip(char *string, char *key) {
	char *temp = malloc(sizeof(char) * strlen(string) + 1), *p = temp;
	int keyLength = strlen(key);

	while (*string) {
		// If current char matchesfirst index of the key to strip, start attempt to strip
		if (*string == key[0]) {
			int offset = 1;

			// Create an index offset to in order to check how many chars match the key
			while (string[offset] == key[offset] && string[offset] != '\0')
				offset++;

			// If the offset (amount of matched chars) matches the key length, we assume it's  a match and we skip the key for copying
			if (offset == keyLength) {
				string += keyLength;
				continue;
			}
		}

		*p++ = *string++;
	}

	*p = 0;
	return temp;
}

int countOccurences(char *string, char *key) {
	char *temp = string;
	int count = 0;

	while (temp) {
		if ((temp = strstr(temp, key))) {
			count++;
			temp += strlen(key);
		}
		else
			return count;
	}

	return count;
}

int indexOf(char *string, char *key) {
	// Search for the key in the string
	int index = (int)(strstr(string, key) - string);

	//If it was found, return the index, else return -1 (to indicate it was not found)
	if (index >= 0)
		return index;
	else
		return -1;
}

char* sortStringAlphabetically(char *toSort) {
	char *sorted = malloc(strlen(toSort) + 1), temp;
	int index = 0, sortLength = strlen(toSort);

	//Sort while first char is valid (We pop off every char one at a time)
	while (index < sortLength) {
		//Compare for the smallest char started at the current index and the next one
		int smallestIndex = index, i = index + 1;

		//While index counter is less than length of toSort
		while (i < sortLength) {
			if (toSort[i] < toSort[smallestIndex])
				smallestIndex = i;
			i++;
		}

		//Save the smallest number and then move index 0 to that index
		temp = toSort[smallestIndex];
		toSort[smallestIndex] = toSort[index];

		sorted[index++] = temp;
	}

	sorted[index] = 0;
	return sorted;
}

int power(int base, int exponent) {
  int num = 1;

  for (int i = 0; i < exponent; i++)
    num *= base;

  return (num);
}

void swap(void *a, void *b) {
	// void *temp = *b;
	// *b = *a;
	// *a = temp;
}
