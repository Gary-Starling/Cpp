#include <iostream>

using namespace std;

void ggg(signed char a) { std::cout << "signed char" << std::endl; }
void ggg(char a) { std::cout << "char" << std::endl; }
void ggg(unsigned char a) { std::cout << "unsigned char" << std::endl; }

void promotion(char &) { std::cout << "char" << std::endl; }
void promotion(int  &) { std::cout << "int"  << std::endl; }
void promotion(long &) { std::cout << "long" << std::endl; }




double square(double i)
{
    return (i * i);
}

int square(int i)
{
    return (i * i);
}

struct Vector2D
{
    Vector2D(double x, double y) : x(x), y(y) {}

    /*т.к. вернём объект*/
    Vector2D mult(double d) const
    {
        return Vector2D(x * d, y * d); //тут запуск конструктора выше
    }

    double mult(Vector2D const &p) const
    {
        return x * p.x + y * p.y;
    }

    double x, y;
};

struct File
{
    void write(char const *s)
    {
        std::cout << "Base class write func" << std::endl;
        std::cout << s << std::endl;
    }
};

struct FormatFile : File
{
    void write(int i)
    {
        std::cout << "Child class write func int" << std::endl;
        std::cout << i << std::endl;
    }
    void write(double d)
    {
        std::cout << "Child class write func double" << std::endl;
        std::cout << d << std::endl;
    }

    using File::write; // using внутри производного кл, метод базового
};

int main(int argc, char const *argv[])
{
    int a = square(3);
    std::cout << a << std::endl;
    double b = square(3.5);
    std::cout << b << std::endl;
    float c = square(3.3f);
    std::cout << c << std::endl;
    int d = square(3.3f);
    std::cout << d << std::endl;

    Vector2D p(1, 2);
    Vector2D q = p.mult(10);
    double r = p.mult(q);

    FormatFile file;

    file.write(10);
    file.write(100.0);
    file.write("Wow! It's reload");


    //ggg('a');
    short sh = 10;
    //promotion(sh); 


    return 0;
}
