#include <iostream>
#include <math.h>

using namespace std;

unsigned gcd(unsigned a, unsigned b);

int main(int argc, char const *argv[])
{
    unsigned a = 0, b = 0;

    cin >> a >> b;

    cout << "NOD IS " << gcd(a, b);

    return 0;
}

unsigned gcd(unsigned a, unsigned b)
{
    unsigned result = 0;

    if (a > b)
    {
        result = a % b;

        if (result == 0)
            return b;
        else
        {
            return gcd(b, result);
        }
    }
    else if (a < b)
    {
        result = b % a;

        if (result == 0)
            return a;
        else
            return gcd(a, result);
    }
    else if (a == b)
     return a;

     return a;

}
