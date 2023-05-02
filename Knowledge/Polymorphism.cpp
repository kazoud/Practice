#include <iostream>
using namespace std;

class Animal{
public:
virtual void cry() {cout << "Whatever." << endl;}
Animal() {}
~Animal() {}
};

class Cat : public Animal
{
    public:
    void cry() override { cout << "Meow meow!" << endl;}
};

class Dog : public Animal
{
    public:
    void cry() override { cout << "Woof woof!" << endl;}
};

/*
Without the virtual keyword on line 6, we get a compilation error because we added the override keywords
and the cry functions would not be overriding anything.
Without the virtual keyword on line 6 nor the override keywords, the code would just print "Whatever."
three times.
*/

int main()
{
    Animal* a = new Animal();
    Dog d;
    Cat c;
    a->cry();
    a = &d;
    a->cry();
    a = &c;
    a->cry();
    return 0;
}