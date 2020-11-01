# include <iostream>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	int mask = ~(1 << (k - 1));
	n &= mask;

	cout << n << endl;

	return 0;
}