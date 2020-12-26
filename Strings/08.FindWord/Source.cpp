#include <iostream>
#include <string.h>

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

int indexOf(char* str, char* substr)
{
	int len1 = strlen(str);
	int len2 = strlen(substr);

	for (int i = 0; i < len1 - len2 + 1; i++)
	{
		bool found = true;

		for (int j = 0; j < len2; j++)
		{
			if (str[i + j] != substr[j])
			{
				found = false;
				break;
			}
		}

		if (found)
		{
			return i;
		}
	}

	return -1;
}

int main()
{
	char str[100];
	cin.getline(str, 100);

	char toReverse[100];
	cin >> toReverse;

	int wordIndex = indexOf(str, toReverse);

	if (wordIndex > 0)
	{
		int wordLength = strlen(toReverse);
		reverseSection(str, wordIndex, wordIndex + wordLength, wordLength);

		cout << str << endl;
	}
	else
	{
		cout << toReverse << " not found" << endl;
	}

	return 0;
}