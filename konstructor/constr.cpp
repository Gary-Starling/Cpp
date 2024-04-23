#include <cstddef> // size_t
#include <cstring> // strlen, strcpy
#include <iostream>

using namespace std;

struct String
{

    /* Создаёт переданную строку*/
    String(const char *str = "")
    {
        this->size = strlen(str);
        this->str = new char[size + 1];
        strcpy(this->str, str);
    }

    /* Заполняет символом, строку из N эл-в */
    String(size_t n, char c)
    {
      this->size = n;
      this->str = new char[n + 1];
      for (size_t i = 0; i < n; i++) {
          this->str[i] = c;
      }
      this->str[n] = '\0';
      
    }

    /* и деструктор */
    ~String()
    {
        delete [] this->str;
    }

    /* Добавляет переданную строку в исходную */
	void append(String &other)
    {
      size_t newsize = 0;
      char *new_str;

      newsize = other.size + this->size;//Вычислим новый размер
      new_str = new char[newsize + 1];  //Выделение под новую строку, +1 Для '\0'
       
      strcpy(new_str, this->str);       //Скопировали 1 часть
      strcat(new_str, other.str);       //Скопировали вторую часть
      new_str[newsize] = '\0';          //Конец строки
      delete [] this->str;              //Удалим старую
      this->str = new_str;              //Присвоим новую
      this->size = newsize;             //Присвоим новый размер
    }

    size_t size;
    char *str;
};

int main(int argc, char const *argv[])
{
    String new_str1("Hello");
    String new_str2(3, 'B');

    cout << new_str1.str << endl;
    cout << new_str2.str << endl;

    new_str1.append(new_str2);

    cout << new_str1.str << endl;

    new_str1.append(new_str1);

    cout << new_str1.str << endl;

    return 0;
}
