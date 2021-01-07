#include <iostream>

using namespace std;

int getDigitSum(int n)
{
	if (n < 10)
	{
		return n;
	}

	return n % 10 + getDigitSum(n / 10);
}


int main()
{
	int n = 0;
	cin >> n;

	cout << getDigitSum(n) << endl;

	return 0;
}