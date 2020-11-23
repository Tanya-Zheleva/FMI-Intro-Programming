#include <iostream>

using namespace std;

const int SIZE = 100;

void readArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}

void mergeArrays(int first[], int n, int second[], int m, int merged[])
{
	int i = 0, j = 0, k = 0;

	while (i < n && j < m)
	{
		if (first[i] < second[j])
		{
			merged[k] = first[i];
			i++;
			k++;
		}
		else
		{
			merged[k] = second[j];
			j++;
			k++;
		}
	}

	while (i < n)
	{
		merged[k] = first[i];
		i++;
		k++;
	}

	while (j < m)
	{
		merged[k] = second[j];
		j++;
		k++;
	}
}

int main()
{
	int n = 0, m = 0;
	cin >> n;
	int first[SIZE] = {};
	int second[SIZE] = {};

	readArray(first, n);
	cin >> m;
	readArray(second, m);

	int merged[2 * SIZE] = {};
	mergeArrays(first, n, second, m, merged);

	printArray(merged, n + m);

	return 0;
}