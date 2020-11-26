#include <iostream>

using namespace std;

bool isPower(long long x, long long n)
{
	if (x == 1)
	{
		return true;
	}

	long long power = 1;

	while (power < x)
	{
		power *= n;
	}

	return power == x;
}

int main()
{
	int n = 0, k = 0;
	cin >> n >> k;
	int arr[101] = { };

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int powersFound = 0;

	for (int i = 0; i < n; i++)
	{
		if (isPower(arr[i], n))
		{
			powersFound++;
		}
	}

	powersFound == k
		? cout << "Yes" << endl
		: cout << "No";

	return 0;
}