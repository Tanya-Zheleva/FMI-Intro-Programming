#include <iostream>

using namespace std;

void reverseSection(char* s, int start, int end, int length)
{
	for (int j = 0; j < length / 2; j++)
	{
		char t = s[start + j];
		s[start + j] = s[end - 1 - j];
		s[end - 1 - j] = t;
	}
}

void reverseEvenPositionWords(char* s)
{
	int length = strlen(s);
	int spaces = 0;

	int i = 0, wordStart = 0, wordsCount = 0, lastSpaceIndex = 0;

	while (i < length)
	{
		if (s[i] == ' ')
		{
			if (wordsCount % 2 == 0)
			{
				int wordLength = i - wordStart;
				int wordEnd = wordStart + wordLength;

				reverseSection(s, wordStart, wordEnd, wordLength);
			}

			wordStart = i + 1;
			wordsCount++;
			lastSpaceIndex = i;
		}

		i++;
	}

	if (wordsCount % 2 == 0 && i == length)
	{
		int wordStart = lastSpaceIndex + 1;
		int wordLength = length - wordStart;

		reverseSection(s, wordStart, length, wordLength);
	}
}


int main()
{
	char input[100];
	cin.getline(input, 100);

	reverseEvenPositionWords(input);

	cout << input << endl;

	return 0;
}