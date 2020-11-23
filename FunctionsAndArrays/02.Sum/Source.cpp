#include <iostream>

using namespace std;

void customSwap(int& a, int& b)
{
	a = a + b;
	b = (a - b) * b;
}

int main()
{
	int a, b;
	cin >> a >> b;

	customSwap(a, b);

	cout << a << " " << b << endl;

	return 0;
}