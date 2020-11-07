#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int newNum = 0;
	long long powerOfTen = pow(10, n - 1);

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		newNum += powerOfTen * x;
		powerOfTen /= 10;
	}

	cout << newNum << endl;

	return 0;
}