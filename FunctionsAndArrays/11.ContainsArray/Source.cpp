#include <iostream>

using namespace std;

void readArr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

int main()
{
	int n, m;
	cin >> n;

	int pattern[100];
	int sequence[100];

	readArr(pattern, n);
	cin >> m;
	readArr(sequence, m);

	int timesFound = 0;

	for (int i = 0; i <= m - n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (pattern[j] != sequence[i + j])
			{
				break;
			}

			if (j == n - 1)
			{
				timesFound++;
			}
		}
	}

	cout << timesFound << endl;

	return 0;
}