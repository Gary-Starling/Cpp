#include <iostream>
using namespace std;

class Cnt
{

public:
    Cnt()
    { //Конструктор по умолчанию
        a = 0;
        b = 0;
    }

    Cnt(int x, int y)
    { //Конструктор с параметрами
        a = x;
        b = y;
    }

    ~Cnt() {} //Деструктор

    void print() { cout << a << " " << b << '\n'; }
    int summ_a_b()
    {
        int c = 0;
        c = a + b;
        return c;
    }

    void set_a(int x);
    void set_b(int y);
    int get_a(void);
    int get_b(void);
    int &bad_set_a(int x);

private:
    int a;
    int b;
};

void Cnt :: set_a(int x)
{
    if(x > 0 && x < 100)
    {
        a = x;
    }
}

void Cnt :: set_b(int y)
{
        if(y > 0 && y < 100)
    {
        b = y;
    }
}

int Cnt :: get_a(void) 
{
    return a;
}

int Cnt :: get_b(void) 
{
    return b;
}

//Danger!!!
int & Cnt :: bad_set_a(int x)
{
  a = x;
  return a;
}

int main(int argc, char const *argv[])
{
    /* Инит с параметрами по умолчанию */
    Cnt counter1;

    counter1.print();

    /* Инит с парметрами конструктора */
    Cnt counter2(10, 20);

    counter2.print();

    cout << counter2.summ_a_b() << endl;

    Cnt counter3(15, 30);

    counter3.set_a(40);
    counter3.set_b(50);
    counter3.print();
    cout << counter3.get_a() << endl;
    cout << counter3.get_b() << endl;
    cout << counter3.summ_a_b() << endl;

    int &refa = counter3.bad_set_a(1000);
    refa = 2000;
    /* =( */
    cout << counter3.get_a() << endl;
    

    return 0;
}
