#include <iostream>
#include <algorithm>
using namespace std;

struct IntArray
{
public:
    IntArray(size_t razmer)
    { //Конструктор с параметрами
        size_ = razmer;
        data_ = new int[razmer];
    }

    void fill_mass(int per)
    {
        for (size_t i = 0; i < size_; i++)
        {
            data_[i] = per;
        }
    }

    void print(void)
    {
        for (size_t i = 0; i < size_; i++)
        {

            cout << data_[i] << endl;
        }
    }

    void swap(IntArray &a)
    {
        std ::swap(size_, a.size_);
        std ::swap(data_, a.data_);
    }

private:
    size_t size_;
    int *data_;
};

int main(int argc, char const *argv[])
{
    IntArray mass1(10);
    IntArray mass2(10);

    mass1.fill_mass(5);  //Заполним пятёрками
    mass2.fill_mass(10); //Заполним десятками

    /* Выведем */

    mass1.print();
    mass2.print();

    mass1.swap(mass2);

    mass1.print();
    mass2.print();

    return 0;
}
