#include <iostream>

using namespace std;

void func(int x, int& y, int* z)
{
	int a = 3, b = 4;

	a = b + y;
	y = x + a;
	z = &a;

	cout << "func x: " << x << endl;
	cout << "func y: " << y << endl;
	cout << "func *z: " << *z << endl;

	cout << "func a: " << a << endl;
	cout << "func b: " << b << endl;
}

int main()
{
	int a = 1, b = 2;

	func(a + b, b, &a);

	cout << "main a: " << a << endl;
	cout << "main b: " << b << endl;

	return 0;
}