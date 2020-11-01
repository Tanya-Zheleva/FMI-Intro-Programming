# include <iostream>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	
	n & (n - 1)
		? cout << "Is not power of two" << endl
		: cout << "Is power of two" << endl;

	return 0;
}