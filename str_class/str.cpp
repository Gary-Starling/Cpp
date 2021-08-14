#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String
{

    /* Реализуйте этот конструктор */
    String(const char *str = "")
    {
        this->size = strlen(str);
        this->str = new char[size + 1];
        strcpy(this->str, str);
    }

    /* Реализуйте конструктор копирования */
    String(const String &other)
        : size(other.size), str(new char[size + 1])
    {
        for (size_t i = 0; i != size; i++)
        {
            str[i] = other.str[i];
        }
        str[size] = '\0';
    }

    /* Реализуйте оператор присваивания */
    String &operator=(const String &other)
    {
        if (this != &other)
        {
            delete[] str;
            size = other.size;
            str = new char[size + 1];
            for (size_t i = 0; i != size; ++i)
                str[i] = other.str[i];

            str[size] = '\0';
        }
        return *this;
    }

    /* Заполняет символом, строку из N эл-в */
    String(size_t n, char c)
    {
        this->size = n;
        this->str = new char[n + 1];
        for (size_t i = 0; i < n; i++)
        {
            this->str[i] = c;
        }
        this->str[n + 1] = '\0';
    }

    /* и деструктор */
    ~String()
    {
        delete[] this->str;
    }

    /* Реализуйте этот метод. */
    void append(String &other)
    {
        size_t newsize = 0;
        char *new_str;

        newsize = other.size + this->size; //Вычислим новый размер
        new_str = new char[newsize + 1];   //Выделение под новую строку, +1 Для '\0'

        strcpy(new_str, this->str); //Скопировали 1 часть
        strcat(new_str, other.str); //Скопировали вторую часть
        new_str[newsize] = '\0';    //Конец строки
        delete[] this->str;         //Удалим старую
        this->str = new_str;        //Присвоим новую
        this->size = newsize;       //Присвоим новый размер
    }

    size_t size;
    char *str;
};

int main(int argc, char const *argv[])
{
    String new_str1("How are you?");
    String new_str2(10, 'b');
    String lol("LOL!");

    new_str1.append(new_str2);

    String new_str3(new_str1);

    new_str3 = lol;
    /* code */
    return 0;
}
