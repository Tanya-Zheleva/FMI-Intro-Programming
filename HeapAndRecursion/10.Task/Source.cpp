#include <iostream>

using namespace std;

void toDecimal(int n, int p, int result)
{
    if (n == 0)
    {
        cout << result << endl;
        return;
    }

    result += (n % 10) * p;
    toDecimal(n / 10, p * 2, result);
}

int main()
{
    int n = 0;
    cin >> n;

    toDecimal(n, 1, 0);

	return 0;
}