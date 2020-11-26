#include <iostream>

using namespace std;

const int SIZE = 101;

int getAverageNeighboursCount(double arr[], int n)
{
	if (n == 1)
	{
		return 0;
	}

	int counter = 0;

	if (arr[0] == arr[1])
	{
		counter++;
	}

	if (n > 2 && arr[n - 1] == arr[n - 2])
	{
		counter++;
	}

	for (int i = 1; i < n - 1; i++)
	{
		double current = arr[i], prev = arr[i - 1], next = arr[i + 1];
		double avg = (prev + next) / 2;

		if (current == avg)
		{
			counter++;
		}
	}

	return counter;
}

int main()
{
	int n = 0;
	cin >> n;

	double numbers[SIZE] = {};

	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}

	int count = getAverageNeighboursCount(numbers, n);
	cout << count << endl;

	return 0;
}