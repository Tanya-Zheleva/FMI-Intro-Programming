#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

bool isValidLetter(char c)
{
	return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z';
}

int getWordsCount(const char* s)
{
	int count = 0;
	int totalLength = strlen(s);

	for (int i = 0; i < totalLength; i++)
	{
		if (s[i] == ' ' || i == totalLength - 1)
		{
			count++;
		}

		while (!isValidLetter(s[i]))
		{
			i++;
		}
	}

	return count + 1;
}

void orderWords(char** words, int n)
{
	for (int i = 0; i < n; i++)
	{
		int minIndex = i;

		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(words[minIndex], words[j]) > 0)
			{
				minIndex = j;
			}
		}

		swap(words[minIndex], words[i]);
	}
}

int main()
{
	char str[1025];
	cin.getline(str, 1025);

	int wordsCount = getWordsCount(str);
	int length = strlen(str);
	char** words = new char* [wordsCount];

	int wordStart = 0, wordIndex = 0;

	for (int i = 0; i < length + 1; i++)
	{
		if (!isValidLetter(str[i]))
		{
			int wordLength = i - wordStart;
			words[wordIndex] = new char[wordLength + 1]{};

			strncpy_s(words[wordIndex], wordLength + 1, (str + wordStart), wordLength);

			while (!isValidLetter(str[i]) && i < length)
			{
				i++;
			}

			wordIndex++;
			wordStart = i;
		}
	};

	orderWords(words, wordsCount);

	for (int i = 0; i < wordsCount; i++)
	{
		cout << words[i] << endl;
	}

	for (int i = 0; i < wordsCount; i++)
	{
		delete[] words[i];
	}

	delete[] words;

	return 0;
}