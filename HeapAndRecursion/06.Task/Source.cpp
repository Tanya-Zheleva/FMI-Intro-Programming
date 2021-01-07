#include <iostream>

using namespace std;

bool fibContains(int a, int b, int k)
{
	if (k <= a)
	{
		return k == a;
	}

	return fibContains(b, a + b, k);
}

//5
//first call (0, 1, 5)
//second call (1, 1, 5)
//third call (1, 2, 5)
//4th call (2, 3, 5)
//5th call (3, 5, 5)
//6th call (5, 8, 5)
//7th call returns k

bool fibContains(int k)
{
	return fibContains(0, 1, k);
}

int main()
{
	int n = 0;
	cin >> n;

	cout << fibContains(n) << endl; //function overloading

	return 0;
}