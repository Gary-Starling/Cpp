/* swap и конструктор копирования */

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

    IntArray(IntArray const &a)
    : size_(a.size_), data_(new int[size_])
    {
        for (size_t i = 0; i != size_; ++i)
        {
            data_[i] = a.data_[i];
        }
        
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

            cout << data_[i] << ' ';
        }
        cout << endl;
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
    cout << "two new object" << endl;
    mass1.print();
    mass2.print();
    cout << "swap this" << endl;
    mass1.swap(mass2);
    cout << "result" << endl;
    mass1.print();
    mass2.print();
    cout << "constructor copy mass3 copy mass1" << endl;
    IntArray mass3(mass1); //Тут должен вызваться конструктор копирования
    cout << "out  result of counstructor copy" << endl;
    mass3.print();

    return 0;
}
