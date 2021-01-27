#include <iostream>

using namespace std;

void increase(int& x)
{
	x++;
}

int decrease(int x)
{
	return x - 1;
}

void mapArray(int* arr, int n, int(*map)(int))
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = map(arr[i]);
	}
}

void print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}

	cout << endl;
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

	print(arr, n);

	mapArray(arr, n, decrease);

	print(arr, n);

	delete[] arr;

	return 0;
}