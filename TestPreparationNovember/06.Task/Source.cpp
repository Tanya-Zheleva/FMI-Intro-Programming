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

double getAverage(int arr[], int n)
{
	double sum = 0.0;

	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}

	return sum / n;
}

int main()
{
	int n = 0;
	cin >> n;
	int arr[101] = {};

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int temp = n;
	double avg = getAverage(arr, n);
	printArray(arr, n);

	for (int i = 0; i < n; i++)
	{
		bool isLastIndex = i == n - 1;

		if (arr[i] < avg)
		{
			removeAtIndex(arr, temp, i);
			i--;
		}

		if (isLastIndex)
		{
			break;
		}
	}

	printArray(arr, temp);

	return 0;
}