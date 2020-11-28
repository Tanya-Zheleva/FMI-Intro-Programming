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

	return x1 + x2 > -2;
}

long long getMaxElement(int arr[], int n)
{
	long long max = pow(arr[0], 2);

	for (int i = 1; i < n; i++)
	{
		if (pow(arr[i], 2) > max)
		{
			max = pow(arr[i], 2);
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

	cout << getMaxElement(validNumbers, validLength) << endl;

	return 0;
}