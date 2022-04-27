
#include <iostream>
#include <string>
using namespace std;


struct Person
{
    virtual string name() const 
    {
        return "Person is ";
    }
};

struct Professor : Person
{
    Professor() {}

    string name()
    {
        return Person::name() + pr;
    }

    string pr = "Professor ";

};

struct Student : Person
{
    Student() {}

    string name() const
    {
        return Person::name() + pr;
    }

    string pr = "Student ";

};

int main(int argc, char const *argv[])
{

    Person p1;
    Professor p2;
    Student p3;


    cout << p1.name() << endl;
    cout << p2.name() << endl;
    cout << p3.name() << endl;

    Person * ptr = &p2;
    cout << ptr->name() << endl;

    return 0;
}
