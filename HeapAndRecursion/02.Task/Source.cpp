#include <iostream>

using namespace std;

int capacity = 10;

void resizeDown(int*& arr, int n)
{
	int* temp = arr;
	arr = new int[capacity /= 2];

	for (int i = 0; i < n; i++)
	{
		arr[i] = temp[i];
	}

	delete[] temp;
}

void resizeUp(int*& arr, int n)
{
	int* temp = arr;
	arr = new int[capacity *= 2];

	for (int i = 0; i < n; i++)
	{
		arr[i] = temp[i];
	}

	delete[] temp;
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
	int n;
	cin >> n;
	int* arr = new int[capacity];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	if (n < capacity / 4)
	{
		resizeDown(arr, n);
	}
	
	print(arr, n);

	resizeUp(arr, n);

	print(arr, n);

	delete[] arr;


	return 0;
}