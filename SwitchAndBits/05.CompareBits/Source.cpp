# include <iostream>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	int low, high;

	low = n & 0x0F; // 0x0F = 0000 1111 & 0000 1010 -> 0000 1010
	high = n & 0xF0; // 0xF0 = 1111 0000 & 0000 1001 -> 0000 0000

	high >>= 4;

	low != high
		? cout << "Different" << endl
		: cout << "Equal" << endl;

	return 0;
}