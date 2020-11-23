#include <iostream>
#include <cmath>

using namespace std;

const int SIZE = 100;

void readArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}

void removeDuplicates(int arr[], int& n)
{
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] == arr[j]) 
			{
				n--;

				for (int k = i; k < n; k++) 
				{
					arr[k] = arr[k + 1];
				}

				i--;
			}
		}
	}
}

void printIntersection(int first[], int n, int second[], int m)
{
	cout << "Intersection: ";
	int intersection[SIZE] = {};
	int insertIndex = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (first[i] == second[j])
			{
				intersection[insertIndex] = first[i];
				insertIndex++;
			}
		}
	}

	removeDuplicates(intersection, insertIndex);
	printArray(intersection, insertIndex);
}

void printDifference(int first[], int n, int second[], int m)
{
	cout << "Only in the first array && not divisible by 17: ";
	int difference[SIZE] = {};
	int insertIndex = 0;

	for (int i = 0; i < n; i++)
	{
		if (first[i] % 17 == 0)
		{
			continue;
		}

		bool found = false;

		for (int j = 0; j < m; j++)
		{
			if (first[i] == second[j])
			{
				found = true;
				break;
			}
		}

		if (!found)
		{
			difference[insertIndex] = first[i];
			insertIndex++;
		}
	}

	removeDuplicates(difference, insertIndex);
	printArray(difference, insertIndex);
}

bool isArmstrongNumber(int n)
{
	if (n < 100 || n > 999)
	{
		return false;
	}

	int sum = 0, temp = n;

	while (temp > 0)
	{
		int digit = temp % 10;
		sum += digit * digit * digit;
		temp /= 10;
	}

	return sum == n;
}

void printArmstrongNumbers(int arr[], int n)
{
	cout << "Armstrong numbers: ";
	int numbers[SIZE] = {};
	int insertIndex = 0;

	for (int i = 0; i < n; i++)
	{
		if (isArmstrongNumber(arr[i]))
		{
			numbers[insertIndex] = arr[i];
			insertIndex++;
		}
	}

	removeDuplicates(numbers, insertIndex);
	printArray(numbers, insertIndex);
}

int main()
{
	int n = 0, m = 0;
	cin >> n;
	int first[SIZE] = {};
	int second[SIZE] = {};

	readArray(first, n);
	cin >> m;
	readArray(second, m);

	printIntersection(first, n, second, m);
	printDifference(first, n, second, m);
	printArmstrongNumbers(first, n);

	return 0;
}