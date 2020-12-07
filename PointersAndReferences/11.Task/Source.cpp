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

void reverseRange(int* arr, int l, int r)
{
	int i = l, j = r;
	int temp;

	while (i < j)
	{
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;

		i++;
		j--;
	}
}

void move(int* arr, int n, int k)
{
	reverseRange(arr, 0, k - 1);
	reverseRange(arr, k, n - 1);
	reverseRange(arr, 0, n - 1);
}

int main()
{
	int n = 0, k = 0;
	int arr[100];

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	printArr(arr, n);
	move(arr, n, k);
	printArr(arr, n);

	return 0;
}