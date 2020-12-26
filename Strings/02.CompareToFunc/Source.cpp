#include <iostream>
#include <string.h>

using namespace std;

int compareTo(char* left, char* right)
{
	int n = strlen(left);
	int m = strlen(right);
	int i = 0;

	while (i < n && i < m)
	{
		if (left[i] < right[i])
		{
			return -1;
		}
		else if (left[i] > right[i])
		{
			return 1;
		}

		i++;
	}

	if (n < m)
	{
		return -1;
	}
	else if (n > m)
	{
		return 1;
	}

	return 0;
}

int main()
{
	int n = 0;
	cin >> n;
	char strings[50][50];

	for (int i = 0; i < n; i++)
	{
		cin >> strings[i];
	}

	int maxIndex = 0;

	for (int i = 1; i < n; i++)
	{
		if (compareTo(strings[maxIndex], strings[i]) < 0)
		{
			maxIndex = i;
		}
	}

	cout << strings[maxIndex] << endl;

	return 0;
}