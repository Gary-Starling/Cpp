#include <iostream>

using namespace std;

void rotate(int a[], unsigned size, int shift);

int main(int argc, char const *argv[])
{
    int mass[5] = {1, 2, 3, 4, 5};
    int temp;

    rotate(mass, sizeof(mass) / sizeof(int), 0);

    

    return 0;
}

void rotate(int a[], unsigned size, int shift)
{
    int temp = 0;

    for (size_t j = 0; j < shift; j++)
    {
        for (size_t i = 0; i < size - 1; i++) //Один проход
        {
            temp = a[i + 1];
            a[i + 1] = a[i];
            a[i] = temp;
        }

        for (size_t k = 0; k < 5; k++)
            cout << a[k] << " ";
            cout << "\n";
    }
}
