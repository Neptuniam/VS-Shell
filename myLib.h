/*	Desc: Converts a hexadecimal number to an int
	    In:	sNum - The hexadecimal number, saved as a string
	   Out: iNum - The integer version of the number
   Notes: Hex must be entered in format '0x<>'
	 Error:	*/
int hexToInt(char *sNum);

/*	Desc: Converts an int type variable into a binary number (formatted as a string)
	    In: num - int version of number to convert.
          bits - number of bits to represent the binary number as
	   Out: binary - String version of the inputted number, now converted to binary
	 Notes:	Will malloc in function, but must be free-ed when finished with it
          Entering '-1' as bits will calculate the binary bit size for you
   Error: */
char* toBinary(int num, int bits);

/*	Desc: Splits a string into a array of strings on a desired key
	    In: string - the string to be split up
          key - the key of which the key is split on
	   Out: char **parsed - the array of strings, containing the now split up input
	 Notes:	Will malloc in function, but must be free-ed when finished with it
          Depends on having access to function from myLib 'countOccurences' to malloc size of array
   Error: string must actually contain null terminator in order to properlly terminate loop
          Must not end on key*/
char** split(char *string, char *key);

/*	Desc: Strips an inputted string of a desired key
	    In: string - the string to be stripped of desired key
          key - the key (string) to strip from the original string
	   Out: temp - the temp string which does not include the key
   Notes: Will malloc in function, but must be free-ed when finished with it
   Error:	Will return -1 if key is not found*/
char* strip(char *string, char *key);

/*	Desc: Counts the number of occurances of a key inside a string
	    In: string - the string to count occurances in
          key - the string to search for
	   Out: count - int representing number of times key was found in string
   Notes:
	 Error:	*/
int countOccurences(char *string, char *key);

/*	Desc: Finds index of a key inside a string
	    In: string - String to find the key inside of
	   Out: int index - index of the key in the string
   Notes:
	 Error:	*/
int indexOf(char *string, char *key);

/*	Desc: Implements selection sort to sort string alphabetically
	    In: toSort - String to be sorted
	   Out:  sorted - The sorted version of the inputted string
   Notes: Will malloc in function, but must be free-ed when finished with it
	 Error:	*/
char* sortStringAlphabetically(char *toSort);

/*	Desc: Returns resultfo base to the poer of exponent
	    In: base - The int we want the power of
          exponenet - the power to
	   Out:  num - the result of the exponent
   Notes: takes two ints and will return and int only
	 Error:	*/
int power(int base, int exponent);


void swap(void *a, void *b);
