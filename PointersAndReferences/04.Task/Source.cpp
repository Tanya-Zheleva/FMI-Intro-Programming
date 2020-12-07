#include <iostream>

using namespace std;

void func(int& x, int* y, int z)
{
	int a = 3, b = 5;

	x = z - b;
	*y = 2 * z + 3 * x;
	z = a + *y;

	cout << "func x: " << x << endl;
	cout << "func *y: " << *y << endl;
	cout << "func z: " << z << endl;

	cout << "func a: " << a << endl;
	cout << "func b: " << b << endl;
}

int main()
{
	int a = 2, b = 4;

	func(b, &a, b);

	cout << "main a: " << a << endl;
	cout << "main b: " << b << endl;

	return 0;
}