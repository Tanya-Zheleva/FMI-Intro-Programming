#include <iostream>

using namespace std;

void printArr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}

void rotateByOne(int arr[], int n)
{
	int last = arr[n - 1];

	for (int i = n - 2; i >= 0; i--)
	{
		arr[i + 1] = arr[i];
	}

	arr[0] = last;
}

void rotate(int arr[], int n, int k)
{
	k %= n;

	for (int i = 0; i < k; i++)
	{
		rotateByOne(arr, n);
		cout << "After " << i + 1 << " rotation ";
		printArr(arr, n);
	}
}

int main()
{
	int n = 0, k = 0;
	cin >> n >> k;
	int arr[101] = {};

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	rotate(arr, n, k);

	return 0;
}