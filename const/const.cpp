#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a = 10;
    const int * p1 = &a; //Указатель на константу
    int const *p2 = &a; //

    /* error */
    //*p1 = 20;
    //*p2 = 30;
    /* ok */
    p1 = 0;
    p2 = 0;

    int * const p3 = &a;
    *p3 = 30; //ok
    /*error*/
    //p3 = 0;
    int const * const p4 = &a;
    /* nothing to do */

    /* const делает неизменяемым тип слева от него */
    int b = 20;
    int * ptr = &b;

    int const & c = b;
    cout << c << endl;


    return 0;
}
