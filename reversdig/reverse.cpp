#include <iostream>

using namespace std;
void input(void);

int main()
{
    input();
    return 0;
}

void input(void)
{
    int dig = 0;

    cin >> dig;

    if (dig != 0)
    {
        input();
        cout << dig << " ";
    }
}