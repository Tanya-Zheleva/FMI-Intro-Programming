#include <iostream>

using namespace std;

const int SIZE = 100;

int main()
{
	int n;
	cin >> n;

	int numbers[SIZE];

	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}

	int maxLength = 0, currentLength = 1, start = 0, end = 0, bestStart = 0, bestEnd = 0;
	/*
	12
	1 1 1 4 5 5 1 3 3 3 3 1
*/

	for (int i = 1; i < n; i++)
	{
		if (numbers[i] == numbers[start])
		{
			currentLength++;
		}
		else
		{
			if (currentLength > maxLength)
			{
				maxLength = currentLength;
				bestEnd = i - 1;
				bestStart = start;
			}

			currentLength = 1;
			start = i;
		}
	}

	if (currentLength > maxLength)
	{
		maxLength = currentLength;
		end = n - 1;
	}

	cout << maxLength << " " << bestStart << " " << bestEnd << endl;

	return 0;
}