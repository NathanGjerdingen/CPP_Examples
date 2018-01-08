#include <iostream>
#include <string>
using namespace std;

/*******************************************Problem***************************************************
Write a function that returns an integer and accepts a pointer to a C-string as an argument.         *
The function should count the number of characters in the string and return that number. Demonstrate *
the function in a simple program that asks the user to input a string, passes it to the function,    *
and then displays the functions return value.                                                        *
*****************************************************************************************************/

/***************************Psudocode************************************
Step01 - Ask user for string, and put it in a char array.               *
Step02 - Pass the pointer of that array through a function.             *
Step03 - Loop through the array. Count the elements.                    *
Step04 - Return the count to main, then display the number of elements. *
************************************************************************/

int main() {
	//Initialize needed variables.
	char str[80];
	char * ptr;
	ptr = str;
	int length = 0;

	//Step01:
	cout << "Please enter a string of 80 characters or less..." << endl;
	cin.getline(str, 80);

	//Step02:
	length = returnLength(ptr);
	cout << "The length of that string is: " << length << endl;
	return 0;
}

int returnLength(char *ptr) {
	int count = 0;

	//Step03:
	while (1) {
		ptr[count++];
		if (ptr[count] == 0)
			break;
	}

	//Step04:
	return count;
}
