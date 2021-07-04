#include <iostream>
using namespace std;

int **create_array2d(size_t a, size_t b);
void free_array2d(int **m, size_t a, size_t b);
int **create_array2d_line(size_t a, size_t b);
int **transpose(const int *const *m, unsigned rows, unsigned cols);

int main(int argc, char const *argv[])
{
    int cnt = 0;

    int **ptr_mass = create_array2d_line(2, 3);

    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            ptr_mass[i][j] = cnt++;
            cout << ptr_mass[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    int **new_mass = transpose(ptr_mass, 2, 3);

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            cout << new_mass[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

int **create_array2d(size_t a, size_t b)
{
    int **m = new int *[a];

    for (size_t i = 0; i != a; ++i)
        m[i] = new int[b];

    return m;
}

void free_array2d(int **m, size_t a, size_t b)
{

    for (size_t i = 0; i != a; ++i)
        delete[] m[i];

    delete[] m;
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


void free_array2d_line(int **m, size_t a, size_t b)
{
    delete[] m[0];
    delete[] m;
}

/* Меняем местами колнку и строку "транспонируем" 
    было [2][3] -> [3][2], каждую строчку исходной матрицы
    запиши в столбец*/
int **transpose(const int *const *m, unsigned rows, unsigned cols)
{
    int **reverse_mass = create_array2d_line(cols, rows);

    /* Идём по строке, превращаемой в столбец */
    for (size_t i = 0; i < rows; i++)
    {
        /* по столбцу -> в строку */
        for (size_t j = 0; j < cols; j++)
        {
            reverse_mass[j][i] = m[i][j];
        }
    }

    return reverse_mass;
}
