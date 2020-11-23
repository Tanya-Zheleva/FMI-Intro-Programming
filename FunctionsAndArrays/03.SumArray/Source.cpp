#include <iostream>

using namespace std;

const int SIZE = 50;

double getSum(double numbers[], int n)
{
	double min = numbers[0], max = numbers[0], sum = numbers[0]; 

	for (int i = 1; i < n; i++)
	{
		double current = numbers[i];

		if (current > max)
		{
			max = current;
		}

		if (current < min)
		{
			min = current;
		}

		sum += current;
	}

	return max + min + (sum / n);
}

int main()
{
	int n;
	cin >> n;

	double numbers[50] = { };

	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}

	double sum = getSum(numbers, n);

	cout << sum << endl;

	return 0;
}