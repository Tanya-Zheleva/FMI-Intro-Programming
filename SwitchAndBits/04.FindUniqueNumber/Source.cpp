#include <iostream>

using namespace std;

int main()
{
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;

	//a ^ a = 0

	int unique = a;
	unique ^= b;
	unique ^= c;
	unique ^= d;
	unique ^= e;

	cout << unique << endl;

	return 0;
}