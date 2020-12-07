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

void removeElement(int* arr, int& n, int x)
{
	bool found = false;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == x)
		{
			found = true;

			for (int j = i; j < n - 1; j++)
			{
				arr[j] = arr[j + 1];
			}

			break;
		}
	}

	if (found)
	{
		n--;
	}
	else
	{
		cout << "No such element found" << endl;
	}
}

int main()
{
	int n = 0, x = 0;
	int arr[100];

	cin >> n >> x;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	printArr(arr, n);
	removeElement(arr, n, x);
	printArr(arr, n);

	return 0;
}