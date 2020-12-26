#include <iostream>
#include <string.h>

using namespace std;

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

void removeFromString(char* s, char* toRemove)
{
	int removeIndex = indexOf(s, toRemove);
	int removeLength = strlen(toRemove);
	int length = strlen(s);

	while (removeIndex >= 0)
	{
		for (int i = 0; i < removeLength; i++)
		{
			for (int j = removeIndex; j < length - 1; j++)
			{
				s[j] = s[j + 1];
			}

			length--;
			s[length] = '\0';
		}

		removeIndex = indexOf(s, toRemove);
	}
}

int main()
{
	char str[100];
	cin.getline(str, 100, ';');

	char toRemove[100];
	cin.getline(toRemove, 100, ';');

	removeFromString(str, toRemove);

	cout << str << endl;

	return 0;
}