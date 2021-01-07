#include <iostream>
#include <algorithm>

using namespace std;

int getMinDigit(int n)
{
	if (n < 10)
	{
		return n;
	}

	return min(n % 10, getMinDigit(n / 10)); //132 
	//first call return (2, getMinDigit(13)) -> min(2, 1) -> 1
	//second call return (3, getMinDigit(1)) -> min(3, 1)
}

int main()
{
	int n = 0;
	cin >> n;

	cout << getMinDigit(n) << endl;

	return 0;
}