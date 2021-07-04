#include <iostream>
using namespace std;

int **create_array2d_line(size_t a, size_t b);
void swap_min(int *m[], unsigned rows, unsigned cols);

int main(int argc, char const *argv[])
{

    int cnt = 30;

    int **ptr_mass = create_array2d_line(4, 5);

    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            ptr_mass[i][j] = cnt--;
            cout << ptr_mass[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    swap_min(ptr_mass, 4, 5);

    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {

            cout << ptr_mass[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    return 0;
}

void swap_min(int *m[], unsigned rows, unsigned cols)
{
    int min = m[0][0];
    size_t index_str = 0;

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            if (m[i][j] < min)
            {
                min = m[i][j];
                index_str = i; //Найдена строчка с минимальным значением
            }
        }
    }

    int *ptr_tmp = m[0];
    m[0] = m[index_str];
    m[index_str] = ptr_tmp;
}

int **create_array2d_line(size_t a, size_t b)
{

    int **m = new int *[a];

    /* Инит первого указателя на строчку */
    m[0] = new int[a * b]; //Сразу все строчки

    /* Инит остальных строчек */
    for (size_t i = 1; i != a; ++i)
        m[i] = m[i - 1] + b;

    return m;
}