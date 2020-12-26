#include <iostream>
#include <string.h>

using namespace std;

bool isVowel(char c)
{
	bool isLowerVowel = c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
	bool isUpperVowel = c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y';

	return isLowerVowel || isUpperVowel;
}

int getVowelsCount(char* s)
{
	int length = strlen(s);
	int found = 0;

	for (int i = 0; i < length; i++)
	{
		if (isVowel(s[i]))
		{
			found++;
		}
	}

	return found;
}

void transformString(char* s, char symbol, char replaceSymbol)
{
	int length = strlen(s);

	for (int i = 0; i < length; i++)
	{
		if (isVowel(s[i]))
		{
			for (int j = i; j < length - 1; j++)
			{
				s[j] = s[j + 1];
			}

			i--;
			length--;
			s[length] = '\0';
		}
		else if (s[i] == symbol)
		{
			s[i] = replaceSymbol;
		}
	}
}

int main()
{
	char str[100];
	cin.getline(str, 100);

	char symbol, replaceSymbol;
	cin >> symbol >> replaceSymbol;

	cout << "Vowels count: " << getVowelsCount(str) << endl;

	transformString(str, symbol, replaceSymbol);

	cout << str << endl;

	return 0;
}