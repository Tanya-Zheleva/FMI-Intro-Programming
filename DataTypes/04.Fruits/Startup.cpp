#include <iostream>

using namespace std;

int main()
{
	cout << "Please enter quantity and price for the following products:" << endl;
	cout << "Apples: ";

	int applesCount = 0;
	double applePrice = 0;
	cin >> applesCount >> applePrice;

	cout << "Oranges: ";

	int orangesCount = 0;
	double orangePrice = 0;
	cin >> orangesCount >> orangePrice;

	cout << "Bananas: ";

	int bananasCount = 0;
	double bananaPrice = 0;
	cin >> bananasCount >> bananaPrice;

	double applesTotal = applesCount * applePrice;
	double orangesTotal = orangesCount * orangePrice;
	double bananasTotal = bananasCount * bananaPrice;
	double orderTotal = applesTotal + orangesTotal + bananasTotal;

	cout << "Your order is: ";
	cout << "apples for " << applesTotal << ", ";
	cout << "oranges for " << orangesTotal << " and ";
	cout << "bananas for " << bananasTotal << ". ";
	cout << "Total: " << orderTotal << endl;

	return 0;
}