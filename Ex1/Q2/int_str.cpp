#include <cstdlib>
#include <iostream>

int strToInt(char* str) {
	
	int i = 0;
	int sign = 1;
	// check for positive/negative signs
	if(str[0] == '+') {
		sign = 1;
		i = 1;
	}
	if(str[0] == '-') {
		sign = -1;
		i = 1;
	}

	int number = 0;
	while(str[i]) {
		number = number * 10 + int(str[i] - '0');
		i ++;
	}
	return sign * number;
}

char* intToStr(int number) {
	
	int sign = 1;
	int length = 0;
	// for negative number 
	if(number < 0) {
		length ++;
		number = -number;
		sign = -1;
	}
	// get string length
	int temp = number;
	do {
		length ++;
		temp /= 10;
	} while(temp);


	char* str = (char *) calloc(length, sizeof(char));
	int digit;
	do {
		digit = number % 10;
		str[--length] = digit + '0';
		number /= 10;
	} while(number);	 

	if(sign == -1) 
		str[0] = '-';

	return str;

}