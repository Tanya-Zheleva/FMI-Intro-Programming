#include <iostream>

using namespace std;

const int SIZE = 100;

int main()
{
	int n = 0;
	cin >> n;

	int numbers[SIZE] = {};

	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}

	for (int i = n - 1; i >= 0; i--)
	{
		cout << numbers[i] << " ";
	}

	cout << endl;

	return 0;
}