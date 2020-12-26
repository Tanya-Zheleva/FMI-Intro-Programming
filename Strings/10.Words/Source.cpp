#include <iostream>
#include <iostream>

using namespace std;

int indexOf(char* str, char* substr, int offset = 0)
{
	int len1 = strlen(str);
	int len2 = strlen(substr);

	for (int i = offset; i < len1 - len2 + 1; i++)
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
	char space[] = " ";

	int spaceIndex = indexOf(str, space);
	int wordStart = 0;

	while (spaceIndex >= 0)
	{
		for (int i = wordStart; i < spaceIndex; i++)
		{
			cout << str[i];
		}

		cout << endl;

		wordStart = spaceIndex + 1;
		spaceIndex = indexOf(str, space, wordStart);
	}

	int length = strlen(str);

	for (int i = wordStart; i < length - 1; i++)
	{
		cout << str[i];
	}

	cout << endl;

	return 0;
}