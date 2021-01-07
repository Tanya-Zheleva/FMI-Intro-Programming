#include <iostream>

using namespace std;

int convertToBinary(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return (n % 2 + 10 * convertToBinary(n / 2));
}

int main()
{
    int n = 0;
    cin >> n;

    cout << convertToBinary(n) << endl;

	return 0;
}