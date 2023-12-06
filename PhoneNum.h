/* David Rochester
 * 11/20/2023
 *
 * This is the header file for PhoneNum class
 * Here we declare various attributes of the PhoneNum class
 * These include conversionT9, toWord, toDigits, and getNextChars
 *
 */

#ifndef PHONENUM_H
#define PHONENUM_H
#include <stdio.h>

	void conversionT9(FILE *in, FILE *out, char type);
	char *toWord(char * digits);
	char *toDigits(char * word);
	char *getNextChars(FILE * in);

	//extra functions
	void textonymFind(char * word);
	char * convertToNums(char * word);

#endif
