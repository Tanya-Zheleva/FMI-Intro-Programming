#include <iostream>

using namespace std;

void printArr(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}

void insertAt(int* arr, int& n, int x, int index)
{
	for (int i = n - 1; i >= index - 1 ; i--)
	{
		arr[i + 1] = arr[i];
	}

	arr[index] = x;
	n++;
}

int main()
{
	int n = 0, x = 0, index = 0;
	int arr[100];

	cin >> n >> x >> index;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	printArr(arr, n);
	insertAt(arr, n, x, index);
	printArr(arr, n);

	return 0;
}