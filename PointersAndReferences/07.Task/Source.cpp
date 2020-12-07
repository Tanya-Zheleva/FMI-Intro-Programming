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

void removeAt(int* arr, int& n, int index)
{
	for (int i = index; i < n - 1; i++)
	{
		arr[i] = arr[i + 1];
	}

	n--;
}

int main()
{
	int n = 0, index = 0;
	int arr[100];

	cin >> n >> index;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	printArr(arr, n);
	removeAt(arr, n, index);
	printArr(arr, n);

	return 0;
}