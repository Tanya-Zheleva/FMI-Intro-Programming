#include <iostream>
#include <string.h>

using namespace std;

bool isPrime(int n)
{
	if (n < 2)
	{
		return false;
	}

	if (n == 2)
	{
		return true;
	}

	if (n % 2 == 0)
	{
		return false;
	}

	for (int i = 3; i * i <= n; i += 2)
	{
		if (n % i == 0)
		{
			return false;
		}
	}

	return true;
}

int getNumLetters(char* str)
{
	int count = 0;

	while (*str != '\0')
	{
		count++;
		str++;
	}

	return count;
}

int getWordsWithPrimeLengthCount(char matrix[][100], int n)
{
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		if (isPrime(getNumLetters(matrix[i])))
		{
			count++;
		}
	}

	return count;
}

char** getNewMatrix(char matrix[][100], int n, size_t(*getLetters)(const char*))
{
	int rows = getWordsWithPrimeLengthCount(matrix, n);
	char** newMatrix = new char* [rows + 1];

	for (int i = 0; i < rows + 1; i++)
	{
		newMatrix[i] = new char[100];
	}

	int currentRow = 0;

	for (int i = 0; i < n; i++)
	{
		if (isPrime(getLetters(matrix[i])))
		{
			strcpy_s(newMatrix[currentRow], getLetters(matrix[i]) + 1, matrix[i]);
			currentRow++;
		}
	}

	newMatrix[currentRow][0] = '\0';

	return newMatrix;
}

int main()
{
	int n = 0;
	cin >> n;
	char matrix[100][100];

	for (int i = 0; i < n; i++)
	{
		cin >> matrix[i];
	}

	char** newMatrix = getNewMatrix(matrix, n, strlen);
	int length = 0;
	
	while (newMatrix[length][0] != '\0')
	{
		cout << newMatrix[length] << endl;
		length++;
	}

	for (int i = 0; i < length; i++)
	{	
		delete[] newMatrix[i];
	}

	delete[] newMatrix;

	return 0;
}