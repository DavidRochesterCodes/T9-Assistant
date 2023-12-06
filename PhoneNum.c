/* David Rochester
 *
 * This is the source code file for PhoneNum class
 * This file serves as the brains behind our T9 project
 * This file stores our digital 'digits' (2-9) that are
 * used to act as our 9 digit keypad (similar to an old school cell phone)
 * Our conversionT9 function takes in our input/output file, as well as a
 * 'switch' to determine if we are converting to/from characters
 *
 */

#include "PhoneNum.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// arrays to represent 'phone digits'
const char two[] = {'a', 'b', 'c', '\0'};
const char three[] = {'d', 'e', 'f', '\0'};
const char four[] = {'g', 'h', 'i', '\0'};
const char five[] = {'j', 'k', 'l', '\0'};
const char six[] = {'m', 'n', 'o', '\0'};
const char seven[] = {'p', 'q', 'r', 's', '\0'};
const char eight[] = {'t', 'u', 'v', '\0'};
const char nine[] = {'w', 'x', 'y', 'z', '\0'};

// conversionT9 function
// This function takes in our input/output file, along
// with 'switch' type, which determines if we are converting
// to or from characters. The function will then loop through each
// line from the input file, passing it to the corresponding function
//(toWord/toDigit). We then append the conversion to our output file.
// Finally, we free up any allocated memory using 'free'.
void conversionT9(FILE *in, FILE *out, char type) {
	char *storeLine;
	char *storeConversion;
	switch (type) {

	case 'd':
		while (!feof(in)) {
			storeLine = getNextChars(in);
			storeConversion = toWord(storeLine);
			if (strlen(storeLine) > 2)
				fprintf(out, "%s\n", storeConversion);
			else
				fprintf(out, "%s", storeLine);
		}
		break;
	case 'l':
		while (!feof(in)) {
			storeLine = getNextChars(in);
			storeConversion = toDigits(storeLine);
			if (strlen(storeLine) > 2)
				fprintf(out, "%s\n", storeConversion);
			else
				fprintf(out, "%s", storeLine);
		}
		break;
	default:
		printf("Error!\nconversionT9 default case!\nExiting program.\n");
		exit(0);
	}

	free(storeConversion);
	free(storeLine);
}

// toWord function
// Takes in a pointer to a set of digits to be converted
// This function dynamically allocates the memory needed for the char* it
// returns We iterate through the set of digits until a '-' is reached. We then
// locate which 'digit' (2-9) our number corresponds to, and finally concatenate
// the corresponding character to our char* that stores the word to be returned.
char *toWord(char *digits) {

	int stringLen = strlen(digits); // get length of set of digits
	char *words;
	words = (char *)malloc(sizeof(char) * stringLen +
						   1); // dynamically allocate memory for ptr
	int len = 0; // keeps track of how many digits (2/22/222) are parsed before
				 // '-' is reached
	char current = '\0'; // stores the current digit

	// convert from num to char

	for (int i = 0; i <= stringLen; i++) { // iterate through set of numbers
		if (isdigit(digits[i])) {		   // if we have a valid digit
			current = digits[i];		   // set current = current digit
			len++;						   // increment length var
		}

		if (digits[i] == '-' ||
			digits[i] == '\0') { // if we have reached a '-' or '\0'
			switch (current) {	 // we will concatenate the corresponding letter
			case '2': {
				strncat(words, &two[len - 1], 1);
				len = 0;
				break;
			}
			case '3': {
				strncat(words, &three[len - 1], 1);
				len = 0;
				break;
			}
			case '4': {
				strncat(words, &four[len - 1], 1);
				len = 0;
				break;
			}
			case '5': {
				strncat(words, &five[len - 1], 1);
				len = 0;
				break;
			}
			case '6': {
				strncat(words, &six[len - 1], 1);
				len = 0;
				break;
			}
			case '7': {
				strncat(words, &seven[len - 1], 1);
				len = 0;
				break;
			}
			case '8': {
				strncat(words, &eight[len - 1], 1);
				len = 0;
				break;
			}
			case '9': {
				strncat(words, &nine[len - 1], 1);
				len = 0;
				break;
			}
			default:
				printf("Error!\nIn default case for toWord()!");
				exit(0);
				break;
			}
		}
	}
	return words;
}

// toDigits function
// This function takes a char* to a string, returns a pointer to
// the corresponding set of numbers based on a 9 digit keypad (abc -> 2-22-222)
// We dynamically allocate the memory needed based on the size of the word,
// and then iterate through the word, comparing each character against our
//'digit' arrays (2,3,4,...9) to find the match. We then find the correspoding
// index of our match, to give us the qty to append to the pointer we return.
char *toDigits(char *word) {

	int stringLen = strlen(word); // get length of word minus null char
	char *digits;
	digits = (char *)malloc(sizeof(char) * 200); // dynamically allocate memory
	int quantity = 0; // store qty of digit to append to digits
	char *ptr;		  // ptr to char if found in 'digit' array
	char num;		  // store 'num' char to be appended to digits
	char dash = '-';

	for (int i = 0; i < stringLen; i++) {

		if (strchr(two, tolower(word[i])) != NULL) { // if char exists in array
			ptr = strchr(two, tolower(word[i])); // get location of found char
			quantity = (ptr - two + 1); // get index (qty of digits to add)
			num = '2';					// digit to append
		} else if (strchr(three, tolower(word[i])) != NULL) {
			ptr = strchr(three, tolower(word[i]));
			quantity = (ptr - three + 1);
			num = '3';
		} else if (strchr(four, tolower(word[i])) != NULL) {
			ptr = strchr(four, tolower(word[i]));
			quantity = (ptr - four + 1);
			num = '4';
		} else if (strchr(five, tolower(word[i])) != NULL) {
			ptr = strchr(five, tolower(word[i]));
			quantity = (ptr - five + 1);
			num = '5';
		} else if (strchr(six, tolower(word[i])) != NULL) {
			ptr = strchr(six, tolower(word[i]));
			quantity = (ptr - six + 1);
			num = '6';
		} else if (strchr(seven, tolower(word[i])) != NULL) {
			ptr = strchr(seven, tolower(word[i]));
			quantity = (ptr - seven + 1);
			num = '7';
		} else if (strchr(eight, tolower(word[i])) != NULL) {
			ptr = strchr(eight, tolower(word[i]));
			quantity = (ptr - eight + 1);
			num = '8';
		} else if (strchr(nine, tolower(word[i])) != NULL) {
			ptr = strchr(nine, tolower(word[i]));
			quantity = (ptr - nine + 1);
			num = '9';
		} else
			quantity = 0;

		for (int j = 0; j < quantity; j++) {
			strncat(digits, &num, 1);
		}
		if (isalpha(word[i + 1])) { // if the next char is a-z/A-Z, print '-'
			strncat(digits, &dash, 1);
		}
	}

	return digits;
}

// getNextChars function
// This function takes in a pointer to the current line from input file
// returns a pointer the next line in our input file
// This function checks if fileptr is null, proceeds if false
// Store the line in an dynamically allocated char*, returning the
// next line each time the function is called
char *getNextChars(FILE *in) {

	if (in == NULL)
		exit(0);

	char *storeLine;
	storeLine = (char *)(malloc(sizeof(char) * 200));

	fgets(storeLine, 200, in);

	return storeLine;
}

// textonymFind function
// This function takes in a char* to a word
// It converts the word to its corresponding 'keys' using
// the convertToNums function. Then we will loop through the dictionary,
// converting each word to digits and then comparing with our passed in word.
// We then print out each 'textonym' that is found. All dynamically allocated
// memory is freed at the end of the function.
void textonymFind(char *word) {
	char *nums;
	nums = convertToNums(word); // get digits associated with word

	FILE *dict;
	dict = fopen("/usr/share/dict/words", "r");
	char wordArr[35];
	char *currentNums;
	currentNums = (char *)malloc(sizeof(char) * 30);
	// here we loop each word, convert to nums, compare with nums, print if
	// match
	while (!feof(dict)) {
		fgets(wordArr, 25, dict);
		wordArr[0] = tolower(wordArr[0]);
		currentNums = convertToNums(wordArr);
		if (strcmp(currentNums, nums) == 0)
			printf("%s", wordArr);
	}
	//free(nums);
	//free(currentNums);
}

// convertToNums function
// This function is used to convert the passed in word
// into the corresponding digits (good --> 4663) and ignoring
// the quantity of digit presses to get to the word. This helps
// us find the textnonyms of the passed in word.
// Returns a char* to the corresponding digits.
char *convertToNums(char *word) {
	int stringLen = strlen(word);
	char *digits;
	digits = (char *)malloc(sizeof(char) * stringLen);
	char num;

	// loop to find which array the current char belongs to
	for (int i = 0; i < stringLen; i++) {
		if (strchr(two, (word[i])) != NULL) {
			num = '2';
		} else if (strchr(three, (word[i])) != NULL) {
			num = '3';
		} else if (strchr(four, (word[i])) != NULL) {
			num = '4';
		} else if (strchr(five, (word[i])) != NULL) {
			num = '5';
		} else if (strchr(six, (word[i])) != NULL) {
			num = '6';
		} else if (strchr(seven, (word[i])) != NULL) {
			num = '7';
		} else if (strchr(eight, (word[i])) != NULL) {
			num = '8';
		} else if (strchr(nine, (word[i])) != NULL) {
			num = '9';
		} else
			num = 0;
		strncat(digits, &num, 1);
	}
	return digits;
}
