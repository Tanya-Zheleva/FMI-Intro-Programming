#include <iostream>
#include <string.h>

using namespace std;

bool isSubstring(char* str, char* substr)
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
			return true;
		}
	}

	return false;
}

int main()
{
	char first[50], second[50];
	cin >> first >> second;

	int len1 = strlen(first);
	int len2 = strlen(second);

	bool isSubstr = len1 > len2 ? isSubstring(first, second) : isSubstring(second, first);

	cout << boolalpha << isSubstr << endl;

	return 0;
}