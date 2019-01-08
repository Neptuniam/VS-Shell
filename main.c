#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "functions.h"
#include "myLib.h"

int main() {
	char **command = malloc(sizeof(char*)), line[256] = "";
	char *commands[256] = { "Use 'exit' or enter to quit!", "sums", "binaryTest,<bits>", "binCon,<num>,<bits>", "hexCon,0x<val>", "split", "strip", "bullshit", "countOccurences", "indexOf,string,key", "sort,<string>", " ", NULL };
	char setDefault[256] = "\n\0";

	displayHelp(commands);
	do {
		//If a default command is not set
		if (strcmp(setDefault, "\n\0") == 0) {
			printf(">>");
			fgets(line, 256, stdin);
		}
		else
			strcpy(line, setDefault);

		// WARNING: cls may only work on windows
		// system("cls");
		if (line[0] == '\n')
			break;

		//Check that the line contains a new line char, then strip it
		if (strstr(line, "\n"))	command[0] = strip(line, "\n");
		else										strcpy(command[0], line);

		//Split the command, index 0 becomes the command called, and remaining indexes are arguements
		if (strstr(line, ","))	command = split(command[0], ",");

		if (strcmp(command[0], "help") == 0)
			displayHelp(commands);
		else if (strcmp(command[0], "sums") == 0)
			summations();
		else if (strcmp(command[0], "binaryTest") == 0)
			binaryTest(atoi(command[1]));
		else if (strcmp(command[0], "binCon") == 0) {
			char binary[256] = "";

			strcpy(binary, toBinary(atoi(command[1]), atoi(command[2])));
			printf("%d in binary is: %s\n", atoi(command[1]), binary);
		}
		else if (strcmp(command[0], "hexCon") == 0)
			printf("%s in decimal is %d\n", command[1], hexToInt(command[1]));
		else if (strcmp(command[0], "split") == 0) {
			char **newString = split("Let's testxyzmultiplexyzsplits just for shitsxyztest", "xyz");
			// char **newString = split(command[1], command[2]);
			int splitIndex = 0;

			while (newString[splitIndex])
				puts(newString[splitIndex++]);
		}
		else if (strcmp(command[0], "strip") == 0) {
			char *string = "Here is a string to use the strip on";
			char *key = "e";

			printf("String: %s\nKey: %s\n\n", string, key);
			puts(strip(string, key));
			// puts(strip(command[1], command[2]));
		}
		else if (strcmp(command[0], "bullshit") == 0)
			runBullshit();
		else if (strcmp(command[0], "countOccurences") == 0) {
			char *string = "this string will have many occurences of the letter 'e'";
			char *key = "e";

			printf("String: %s\nKey: %s\n", string, key);

			printf("Count: %d\n", countOccurences(string, key));
		}
		else if (strcmp(command[0], "indexOf") == 0) {
			char *string = command[1];
			char *key = command[2];

			printf("%s in %s is at: %d\n", key, string, indexOf(string, key));
		}
		else if (strcmp(command[0], "sort") == 0) {
			puts(sortStringAlphabetically(command[1]));
		}
		else if (strcmp(command[0], "exit") == 0)
			//Do nothing
			printf(" ");
		else
			puts("Unknown command!");

		puts("");

		// if (strcmp(setDefault, "") != 0)
		// 	getchar();

	} while (strcmp(command[0], "exit") != 0);

	return 0;
}
