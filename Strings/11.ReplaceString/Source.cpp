#include <iostream>
#include <string.h>

using namespace std;

#pragma warning(disable : 4996)

char* replaceWord(char* s, char* word, char* replace)
{
    int timesFound = 0, i = 0;
    int wordLen = strlen(word);
    int replaceLen = strlen(replace);

    for (i = 0; s[i] != '\0'; i++) {
        if (strstr(&s[i], word) == &s[i]) {
			timesFound++;
            i += replaceLen - 1;
        }
    }

	int diff = wordLen > replaceLen ? wordLen - replaceLen : replaceLen - wordLen;
	char* result = new char[i + timesFound * diff + 1]; //length of the array with replaced words
	int k = 0;

	while (*s) 
	{
		if (strstr(s, word) == s) 
		{
			strcpy(&result[k], replace);
			k += replaceLen;
			s += wordLen;
		}
		else
		{
			result[k] = *s;
			k++;
			s++;
		}
	}

	result[k] = '\0';

	return result;
}

int main()
{
	char str[100], word[100], replace[100];
	cin.getline(str, 100);
	cin >> word >> replace;

	char* newString = replaceWord(str, word, replace);

	cout << newString << endl;

	delete[] newString;

	return 0;
}