#include <iostream>

using namespace std;

long long getPower(int x, int p)
{
	long long result = 1;

	for (int i = 0; i < p; i++)
	{
		result *= x;
	}

	return result;
}

bool hasEvenDigits(long long n)
{
	if (n == 0)
	{
		return true;
	}

	while (n > 0)
	{
		int digit = n % 10;

		if (digit % 2 != 0)
		{
			return false;
		}

		n /= 10;
	}

	return true;
}

bool isPerfectSquare(long long n)
{
	for (long long i = 1; i * i <= n; i++)
	{
		if (i * i == n)
		{
			return true;
		}
	}

	return false;
}

bool isPerfectSquareBinary(long long n) 
{
	long long right = n, left = 1;

	while (left <= right)
	{
		long long mid = (left + right) / 2;

		if (mid * mid == n)
		{
			return true;
		}

		mid * mid < n
			? left = mid + 1
			: right = mid - 1;
	}

	return false;
}

int main()
{
	int k = 0;
	cin >> k;

	long long lower = getPower(10, k - 1);
	long long upper = getPower(10, k) - 1;

	for (int i = lower; i <= upper; i++)
	{
		if (hasEvenDigits(i) && isPerfectSquare(i))
		{
			cout << i << " ";
		}
	}

	cout << endl;

	return 0;
}