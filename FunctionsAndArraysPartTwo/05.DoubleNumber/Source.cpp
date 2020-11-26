#include <iostream>

using namespace std;

int getDigitsCount(long long n)
{
	int count = 0;

	while (n > 0)
	{
		count++;
		n /= 10;
	}

	return count;
}

long long getPowerOfTen(long long p)
{
	long long res = 1;

	for (int i = 0; i < p; i++)
	{
		res *= 10;
	}

	return res;
}

int main()
{
	long long a, b = 0;
	cin >> a >> b;

	for (long long i = 1; ; i++)
	{
		int digits = getDigitsCount(i);
		long long x = i * getPowerOfTen(digits) + i;

		if (x > b)
		{
			break;
		}

		if (x >= a)
		{
			cout << x << " ";
		}
	}

	cout << endl;

	return 0;
}