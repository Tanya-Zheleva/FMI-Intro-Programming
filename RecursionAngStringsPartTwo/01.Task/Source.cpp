#include <iostream>

using namespace std;

int getMaxSuffixLength(int a, int b)
{
	if (a % 10 != b % 10 || a == 0)
	{
		return 0;
	}

	return a % 10 + 10 * getMaxSuffixLength(a / 10, b / 10);
}

int main()
{
	int a = 0, b = 0;
	cin >> a >> b;

	cout << getMaxSuffixLength(a, b) << endl;

    return 0;
}
