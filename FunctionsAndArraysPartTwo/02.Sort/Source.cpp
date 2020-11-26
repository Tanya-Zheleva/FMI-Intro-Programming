#include <iostream>

using namespace std;

void swapNumbers(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void sortArr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int min = i; // 5 21  1 3 

		for (int j = i + 1; j < n; j++)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}

		swapNumbers(arr[min], arr[i]);
	}
}

int main()
{
	int n = 0;
	cin >> n;
	int arr[100] = {};

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sortArr(arr, n);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}