#include <iostream>

using namespace std;

void print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}

void generate(int* arr, int n, int k, int i = 0)
{
	if (i > n)
	{
		return;
	}

	if (i == n)
	{
		print(arr, n);

		return;
	}

	for (int j = 0; j < k; j++)
	{
		arr[i] = j;
		generate(arr, n, k, i + 1);
	}
}

int main()
{
	int n = 0, k = 0;
	cin >> n >> k;

	int* arr = new int[n];

	generate(arr, n, k);

	delete[] arr;

	return 0;
}