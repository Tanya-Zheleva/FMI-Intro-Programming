#include <iostream>
#include <string.h>

using namespace std;

void merge(char* first, char* second, char* merged)
{
	if (!*first)
	{
		strcpy_s(merged, strlen(second) + 1, second);
	}
	else
	{
		if (!*second)
		{
			strcpy_s(merged, strlen(first) + 1, first);
		}
		else
		{
			if (*first > *second)
			{
				*merged = *second;
				merge(first, second + 1, merged + 1);
			}
			else
			{
				*merged = *first;
				merge(first + 1, second, merged + 1);
			}
		}
	}
}

int main()
{
	char first[100];
	char second[100];

	cin.getline(first, 100);
	cin.getline(second, 100);

	char* merged = new char[strlen(first) + strlen(second) + 1];

	merge(first, second, merged);

	cout << merged << endl;

	delete[] merged;

	return 0;
}