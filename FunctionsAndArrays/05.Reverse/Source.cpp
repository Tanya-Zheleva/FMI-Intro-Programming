#include <iostream>

using namespace std;

const int SIZE = 100;

int main()
{
	int n;
	cin >> n;

	int numbers[SIZE] = { };

	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}

	for (int i = 0; i < n / 2; i++)
	{
		int temp = numbers[i];
		numbers[i] = numbers[n - i - 1];
		numbers[n - i - 1] = temp;
	}

	for (int i = 0; i < n; i++)
	{
		cout << numbers[i] << " ";
	}

	cout << endl;

	return 0;
}