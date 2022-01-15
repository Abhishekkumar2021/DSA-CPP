#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x = 10;

    // >> operator is used to divide by some powers of 2.
    cout << x << " divided by 2 = " << (x >> 1) << endl;
    cout << x << " divided by 4 = " << (x >> 2) << endl;
    cout << x << " divided by 8 = " << (x >> 3) << endl;

    // << operator is used to multiply by some powers of 2.
    cout << x << " multiply by 2 = " << (x << 1) << endl;
    cout << x << " multiply by 4 = " << (x << 2) << endl;
    cout << x << " multiply by 8 = " << (x << 3) << endl;

    printf("%d in hexadecimal is = %x\n", x, x);
    printf("%d in address type is = %p\n", x, x);
    printf("%d in octal is = %o\n", x, x);

    // negative of a number x = ~x+1  //this is also the 2's complement.
    // 1's complement = ~x
    cout << "negative of " << x << " is = " << ~x + 1;
}
