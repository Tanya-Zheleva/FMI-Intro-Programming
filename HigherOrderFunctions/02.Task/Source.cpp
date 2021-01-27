#include <iostream>

using namespace std;

typedef int (*mapBiary)(int);

void mapMatrix(int** m, int n, mapBiary binaryMap, int(*octalMap)(int))
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			m[i][j] = i % 2 == 0 ? binaryMap(m[i][j]) : octalMap(m[i][j]);
		}
	}
}

int toOctal(int x)
{
	int n = 0, remainder, i = 1;

	while (x != 0)
	{
		remainder = x % 8;
		x /= 8;
		n += remainder * i;
		i *= 10;
	}

	return n;
}

int toBinary(int x)
{
	int n = 0, remainder, i = 1;

	while (x != 0)
	{
		remainder = x % 2;
		x /= 2;
		n += remainder * i;
		i *= 10;
	}

	return n;
}

int main()
{
	int n = 0;
	cin >> n;

	int** matrix = new int* [n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];

		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}

	cout << endl;

	mapMatrix(matrix, n, toBinary, toOctal);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << ' ';
		}

		cout << endl;
	}

	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;

	return 0;
}