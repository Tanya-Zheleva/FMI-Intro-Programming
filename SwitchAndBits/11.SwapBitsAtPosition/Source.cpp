#include <iostream>

using namespace std;

int main()
{
	int n, p, q;
	cin >> n >> p >> q;

	n ^= (1 << p);
	n ^= (1 << q);

	cout << n << endl;

	return 0;
}