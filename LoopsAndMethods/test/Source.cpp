#include <iostream>

using namespace std;

int main()
{
    int m, n, k;
    cin >> m >> n >> k;

    for (int i = m; i <= n; i++)
    {
        int temp = i;
        int digits = 0;

        while (temp != 0)
        {
            digits++;
            temp /= 10;
        }

        if (k <= digits)
        {
            int num = 0;
            int power = 1;

            for (int j = 0; j < k - 1; j++)
            {
                power *= 10;
            }

            num = i / (power * 10) * power + i % power;

            if (num != 0 && i % num == 0)
            {
                cout << i << " ";
            }
        }
    }

    cout << endl;

    return 0;
}