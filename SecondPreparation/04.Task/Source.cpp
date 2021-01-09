#include <iostream>
#include <string.h>

using namespace std;

bool isLetter(char c)
{
	return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

int getWordsCount(char* s)
{
	int wordsCount = 0, length = strlen(s);

	for (int i = 0; i < length; i++)
	{
		if (!isLetter(s[i]) || i == length - 1)
		{
			wordsCount++;
		}

		while (!isLetter(s[i]))
		{
			i++;
		}
	}

	return wordsCount;
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

char** getUnique(char** words, int n, int& size)
{
	char** unique = new char* [n];

	int length = strlen(words[0]);
	unique[size] = new char[length + 1];
	strcpy_s(unique[size], length + 1, words[0]);

	size++;

	for (int i = 1; i < n; i++)
	{
		if (strcmp(words[i - 1], words[i]) != 0)
		{

			length = strlen(words[i]);
			unique[size] = new char[length + 1];
			strcpy_s(unique[size], length + 1, words[i]);

			size++;
		}
	}

	return unique;
}

int countWordOccurrences(char** words, char* word, int n)
{
	int counter = 0;

	for (int i = 0; i < n; i++)
	{
		if (strcmp(words[i], word) == 0)
		{
			counter++;
		}
	}

	return counter;
}

void orderByOccurrences(char** words, int n, char** unique, int m)
{
	for (int i = 0; i < m; i++)
	{
		int maxIndex = i, maxOccurrences = countWordOccurrences(words, unique[i], n);

		for (int j = i + 1; j < m; j++)
		{
			int currentOccurrences = countWordOccurrences(words, unique[j], n);

			if (currentOccurrences > maxOccurrences)
			{
				maxIndex = j;
				maxOccurrences = currentOccurrences;
			}
		}

		swap(unique[maxIndex], unique[i]);
	}
}

int main() {
	char s[1025];
	cin.getline(s, 1025);

	int wordsCount = getWordsCount(s);

	char** words = new char* [wordsCount];
	int wordsStartIndex = 0, wordCurrentIndex = 0, length = strlen(s);

	for (int i = 0; i < length + 1; i++)
	{
		if (!isLetter(s[i]))
		{
			int wordLength = i - wordsStartIndex;
			words[wordCurrentIndex] = new char[wordLength + 1]{};

			strncpy_s(words[wordCurrentIndex], wordLength + 1, (s + wordsStartIndex), wordLength);

			while (!isLetter(s[i]))
			{
				i++;
			}

			wordsStartIndex = i;
			wordCurrentIndex++;
		}
	}

	orderWords(words, wordsCount);

	int uniqueCount = 0;
	char** uniqueWords = getUnique(words, wordsCount, uniqueCount);

	orderByOccurrences(words, wordsCount, uniqueWords, uniqueCount);

	for (int i = 0; i < uniqueCount; i++)
	{
		cout << uniqueWords[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < uniqueCount; i++)
	{
		delete[] uniqueWords[i];
	}

	delete[] uniqueWords;

	for (int i = 0; i < wordsCount; i++)
	{
		delete[] words[i];
	}

	delete[] words;

	return 0;
}