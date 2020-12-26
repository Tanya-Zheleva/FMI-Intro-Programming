#include <iostream>
#include <string.h>

using namespace std;

int getLength(char* s)
{
	int length = 0;

	while (s[length] != '\0')
	{
		length++;
	}

	return length;
}

int main()
{
	char str[50];
	cin >> str;

	cout << getLength(str) << endl;

	return 0;
}