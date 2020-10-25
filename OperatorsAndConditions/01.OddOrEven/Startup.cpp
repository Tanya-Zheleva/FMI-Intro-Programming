#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	n % 2 == 0
		? cout << "Even" << endl
		: cout << "Odd" << endl;

	return 0;
}