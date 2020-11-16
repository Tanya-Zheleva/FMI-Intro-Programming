#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    /*unsigned x, n, p;
    cin >> x >> n >> p;
    unsigned l = p;
    unsigned r = n + p - 1;

    std::bitset<8> b(x);
    std::cout << b << ' ' << x << '\n';

    unsigned temp = ((1 << r) - 1) ^ ((1 << (l - 1)) - 1);

    unsigned result = (x ^ temp);

    std::bitset<8> d(result);
    std::cout << d << ' ' << result << '\n';*/
    int n;
    cin >> n;

    int k = 63;
    std::bitset<8> b(n);
    std::cout << b << ' ' << n << '\n';

    cout << "&" << endl;

    std::bitset<8> c(k);
    std::cout << c << ' ' << k << '\n';
    cout << "=" << endl;

    int r = n & k;
    std::bitset<8> d(r);
    std::cout << d << ' ' << r << '\n';

    return 0;
}