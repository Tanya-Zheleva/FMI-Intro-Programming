#include <iostream>
#include <cmath>

using namespace std;

const int SIZE = 100;

bool isFib(int n)
{
	int a = 1;
	int b = 1;

	while (a <= n)
	{
		if (a == n)
		{
			return true;
		}

		int temp = a + b;
		a = b;
		b = temp;
	}

	return false;
}

bool isPerfectSquare(int x)
{
	int s = sqrt(x);

	return s * s == x;
}

bool isFibShort(int n)
{
	if (n == 0)
	{
		return false;
	}

	return isPerfectSquare(5 * n * n + 4) || isPerfectSquare(5 * n * n - 4);
}

int main()
{
	int n = 0;
	cin >> n;

	int a[SIZE] = {};

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	bool hasFib = false;

	for (int i = 0; i < n; i++)
	{
		if (isFib(a[i]))
		{
			hasFib = true;
			break;
		}
	}

	cout << hasFib << endl;

	return 0;
}