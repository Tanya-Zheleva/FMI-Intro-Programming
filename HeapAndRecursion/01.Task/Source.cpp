#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

bool isUpperCase(char c)
{
	return 'A' <= c && c <= 'Z';
}

int difference(char* firstWord, char* secondWord)
{
	bool checked[2][26]{};
	int diffCount = 0;

	for (int i = 0; i < strlen(firstWord); i++)
	{
		int row = isUpperCase(firstWord[i]);
		int index = firstWord[i] - (row == 1 ? 'A' : 'a');

		if (!checked[row][index])
		{
			bool found = false;

			for (int j = 0; j < strlen(secondWord); j++)
			{
				if (firstWord[i] == secondWord[j])
				{
					found = true;
					break;
				}
			}

			if (!found)
			{
				diffCount++;
			}

			checked[row][index] = true;
		}
	}

	return diffCount;
}

int getWordsCount(char* sentence)
{
	int wordsCount = 0;

	for (int i = 0; i < strlen(sentence); i++)
	{
		if (sentence[i] == ' ')
		{
			wordsCount++;
		}

		while (sentence[i] == ' ')
		{
			i++;
		}
	}

	return wordsCount + 1;
}

int main()
{
	char sentence[100];
	cin.getline(sentence, 100);

	int wordsCount = getWordsCount(sentence);

	char** words = new char* [wordsCount];

	int wordsStartIndex = 0;
	int wordCurrentIndex = 0;

	for (int i = 0; i < strlen(sentence); i++)
	{
		if (sentence[i] == ' ' || i == strlen(sentence) - 1)
		{
			words[wordCurrentIndex] = new char[i - wordsStartIndex + 1]{};
			strncpy_s(words[wordCurrentIndex], i - wordsStartIndex + 1, (sentence + wordsStartIndex), i - wordsStartIndex);

			while (sentence[i] == ' ')
			{
				i++;
			}

			wordsStartIndex = i;
			wordCurrentIndex++;
		}
	}

	int minDifference = 100;
	int minIndexes[2] = {};

	for (int i = 0; i < wordsCount - 1; i++)
	{
		for (int j = i + 1; j < wordsCount; j++)
		{
			if (strcmp(words[i], words[j]) != 0)
			{
				int diff = difference(words[i], words[j]) + difference(words[j], words[i]);

				if (minDifference >= diff)
				{
					minIndexes[0] = i;
					minIndexes[1] = j;
					minDifference = diff;
				}
			}
		}
	}

	cout << words[minIndexes[0]] << " " << words[minIndexes[1]] << " " << minDifference << endl;

	return 0;
}