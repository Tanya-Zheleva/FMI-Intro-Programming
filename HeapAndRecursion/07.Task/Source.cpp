#include <iostream>

using namespace std;

bool isPrime(int n, int i = 2)
{
	if (n <= 2)
	{
		return n == 2;
	}

	if (n % i == 0)
	{
		return false;
	}

	if (i * i > n)
	{
		return true;
	}

	return isPrime(n, i + 1);
}

void printPrimes(int n, int i = 1)
{
	if (i <= n)
	{
		if (n % i == 0 && isPrime(i))
		{
			cout << i << endl;
		}

		printPrimes(n, i + 1);
	}
}

int main()
{
	int n = 0;
	cin >> n;

	cout << boolalpha << isPrime(n) << endl;
	printPrimes(n);

	return 0;
}