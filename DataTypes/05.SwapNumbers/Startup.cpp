#include <iostream>

using namespace std;

int main()
{
	int a = 0, b = 0;
	cin >> a >> b;

	//First
	int temp = a;
	a = b;
	b = temp;

	cout << "After first swap: " << a << " " << b << endl;

	//Second
	a = a + b;
	b = a - b;
	a = a - b;

	cout << "After second swap: " << a << " " << b << endl;

	//Third
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;

	cout << "After third swap: " << a << " " << b << endl;

	return 0;
}