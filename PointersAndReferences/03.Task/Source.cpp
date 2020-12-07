#include <iostream>

using namespace std;

void func(int& x, int* y, int z)
{
	int a = 7, b = 3;

	x = z + b;
	*y = z + x;
	z = a;

	cout << "func x: " << x << endl;
	cout << "func *y: " << *y << endl;
	cout << "func z: " << z << endl;

	cout << "func a: " << a << endl;
	cout << "func b: " << b << endl;
}

int main()
{
	int a = 5, b = 1;

	func(b, &a, b);

	cout << "main a: " << a << endl;
	cout << "main b: " << b << endl;

	return 0;
}