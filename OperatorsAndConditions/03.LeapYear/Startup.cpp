#include <iostream>

using namespace std;

int main()
{
	int year = 0;
	cin >> year;

	bool isLeap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

	isLeap
		? cout << "Leap" << endl
		: cout << "Not leap" << endl;

	return 0;
}