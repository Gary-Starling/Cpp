
#include <iostream>

 struct Cls {
 Cls(char c, double d, int i);
 public:
 Cls()
 {
     c = 1; d = 2.0; i = 36;
 }
 private:
      char c;
      double d;
      int i;
  };
 
 



// Эта функция должна предоставить доступ к полю c объекта cls.
// Обратите внимание, что возвращается ссылка на char, т. е.
// доступ предоставляется на чтение и запись.
char &get_c(Cls &cls) {
    return *(char *)(&cls);
}

// Эта функция должна предоставить доступ к полю d объекта cls.
// Обратите внимание, что возвращается ссылка на double, т. е.
// доступ предоставляется на чтение и запись.
double &get_d(Cls &cls) {
    return *((double *)(&cls) + 1);
}

// Эта функция должна предоставить доступ к полю i объекта cls.
// Обратите внимание, что возвращается ссылка на int, т. е.
// доступ предоставляется на чтение и запись.
int &get_i(Cls &cls) {
   return *((int *)(&cls) + 4);
}

int main(int argc, char const *argv[])
{
    Cls cl1;

    char copy_a;
    double copy_b;
    int copy_c;

    copy_a = get_c(cl1);
    copy_b = get_d(cl1);
    copy_c = get_i(cl1);

    return 0;
}
