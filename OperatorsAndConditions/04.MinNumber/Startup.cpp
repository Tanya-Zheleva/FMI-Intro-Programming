#include <iostream>

using namespace std;

int main()
{
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;

	int min = a > b ? b : a;
	min = min > c ? c : min;

	cout << "Min number is: " << min << endl;

	return 0;
}