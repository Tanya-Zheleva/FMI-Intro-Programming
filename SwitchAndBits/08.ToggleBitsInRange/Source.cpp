#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    unsigned x, n, p;
    cin >> x >> n >> p;
    unsigned l = p;
    unsigned r = n + p - 1;

    std::bitset<8> b(x);
    std::cout << b << ' ' << x << '\n';

    unsigned temp = ((1 << r) - 1) ^ ((1 << (l - 1)) - 1);

    unsigned result = (x ^ temp);

    std::bitset<8> d(result);
    std::cout << d << ' ' << result << '\n';

    return 0;
}