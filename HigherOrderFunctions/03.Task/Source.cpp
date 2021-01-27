#include <iostream>

using namespace std;

typedef bool(*compare)(int, int);

bool isGreater(int a, int b)
{
	return a > b;
}

void sort(int* arr, int n, compare comparator)
{
	for (int i = 0; i < n; i++)
	{
		int swapIndex = i;

		for (int j = i + 1; j < n; j++)
		{
			if (comparator(arr[i], arr[j]))
			{
				swapIndex = j;
			}
		}

		swap(arr[i], arr[swapIndex]);
	}
}

int main()
{
	int n = 0;
	cin >> n;
	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, n, isGreater);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}

	cout << endl;

	delete[] arr;

	return 0;
}