#include <iostream>

using namespace std;

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}

void removeAtIndex(int arr[], int& n, int i)
{
	n = n - 1;

	for (int j = i; j < n; j++)
	{
		arr[j] = arr[j + 1];
	}
}

int getPositiveSum(int arr[], int n)
{
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > 0)
		{
			sum += arr[i];
		}
	}

	return sum;
}

int main()
{
	int n = 0;
	cin >> n;
	int arr[301] = {};

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	printArray(arr, n);
	int newLength = n;
	int replaceSum = getPositiveSum(arr, n);

	for (int i = 0; i < n; i++)
	{
		int end = i, length = 1;
		bool isLastIndex = i == n - 1;

		for (int j = i + 1; j < newLength; j++)
		{
			if (arr[j] != arr[i])
			{
				break;
			}

			length++;
			end++;
		}

		if (length >= 3)
		{
			int removeIndex = i + 1;
			arr[i] = replaceSum;

			for (int j = i; j < end; j++)
			{
				removeAtIndex(arr, newLength, removeIndex);
			}
		}

		if (isLastIndex)
		{
			break;
		}
	}

	printArray(arr, newLength);

	return 0;
}