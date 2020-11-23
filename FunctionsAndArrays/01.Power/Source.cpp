#include <iostream>

using namespace std;

long long getPower(int n, int p)
{
	long long result = 1;

	for (int i = 0; i < p; i++)
	{
		result *= n;
	}

	return result;
}

long long getNumber(int x, int n)
{
	return getPower(x, getPower(n, n));
}

int main()
{
	int x = 0, n = 0;
	cin >> x >> n;

	cout << getNumber(x, n) << endl;

	return 0;
}