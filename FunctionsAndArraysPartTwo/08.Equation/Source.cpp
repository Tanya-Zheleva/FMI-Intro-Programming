#include <iostream>
#include <cmath>

using namespace std;

bool hasValidRoots(int k)
{
	double a = k;
	double b = k * k - k + 19;
	double c = 10;

	double discriminant = b * b - 4 * (a * c);

	if (discriminant <= 0)
	{
		return false;
	}

	double x1 = (-b + sqrt(discriminant)) / (2 * a);
	double x2 = (-b - sqrt(discriminant)) / (2 * a);

	return x1 + x2 < -2;
}

int getMaxElement(int arr[], int n)
{
	int max = arr[0];

	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	return max;
}

int main()
{
	int n = 0;
	cin >> n;
	int arr[101] = {};

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int validNumbers[101] = {};
	int validLength = 0;

	for (int i = 0; i < n; i++)
	{
		if (hasValidRoots(arr[i]))
		{
			validNumbers[validLength] = arr[i];
			validLength++;
		}
	}

	int max = getMaxElement(validNumbers, validLength);

	cout << max << endl;

	return 0;
}