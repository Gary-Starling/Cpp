#include <iostream>

const char * some = "Hello Harry";

struct Foo
{
public:
    Foo()
    {
        msg = "Hello";
    }

    ~Foo()
    {
        std::cout << "Destructor called " << std::endl;
    }

    void say() const
    {
        std::cout << "Foo says: " << msg << "\n";
    }

protected:
    Foo(const char *msg) : msg(msg) {}

private:
    const char *msg;
};

struct HACK : Foo
{
 void print(const char * data)
 {
  std::cout << data << std::endl;   
 }
};

using namespace std;

int main()
{
    Foo obj;
    HACK obj1;

    obj.say();
    obj1.say();
    obj1.print(some);
    return 0;
}