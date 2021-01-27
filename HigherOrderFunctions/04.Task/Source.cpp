#include <iostream>

using namespace std;

typedef int(*transform)(int);

void apply(int* arr, int n, transform f, transform g)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = f(g(arr[i]));
	}
}

int addSeven(int x)
{
	return x + 7;
}

int multiplyByFive(int x)
{
	return x * 5;
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

	cout << endl;

	apply(arr, n, addSeven, multiplyByFive);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}

	cout << endl;

	delete[] arr;

	return 0;
}