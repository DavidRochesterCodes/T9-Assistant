# T9-Assistant
T9 Assistant Project!
David Rochester Jr.
Email: roches4@clemson.edu

Compile instructions
------------------------
1. Download PhoneNum.c && PhoneNum.h; Type the following command once in your directory: gcc -c PhoneNum.c
2. Create your driver.c, include PhoneNum.h in the header. Compile: gcc driver.c PhoneNum.o
3. ./a.out -h will launch help menu
4. ./a.out <input file> <output file> will launch program (converts digits to words)
	- This mode requires input file to be a .txt of digits you wish to convert to words
5. ./a.out -L <input file> <output file> will launch program (converts words to digits)
	- This mode requires input file to be a .txt of words you wish to convert to digits

If no input/output files are present, you can create a quick input.txt and output.txt file to use.
Following the instruction above with your newly created files will give the desired results.
