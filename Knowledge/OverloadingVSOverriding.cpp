#include <iostream>
using namespace std;

/*
Below is an example of function overloading, C++ understands the difference between 
the two functions because their arguments are not the same. Resolved at compile-time. Overloading.
*/ 

float Area(float x)
{
    return x*x;
}

float Area(float x, float y)
{
    return x*y;
}

/*
In the below example, the function signature is the same, but what differs is the class of the
object the method is called on. It is resolved at runtime, this is function overriding.
*/

class Shape {
    public:
    virtual float Area() = 0;
};

class Circle : public Shape
{
    private:
    float radius = 0;

    public:
    float Area() override
    {
        return 3.14 * radius;
    }
    Circle(float a) : radius(a) {}
};

class Square: public Shape
{
    private:
    float side = 0;
    public:
    float Area() override
    {
        return side*side;
    }
    Square(float a) : side(a) {}
};


int main()
{
    cout << Area(4.0) << endl;
    cout << Area(4.0, 10.0) << endl;
    Shape* ptr;
    Circle c(5.0);
    Square s(5.0);
    ptr = &c;
    cout << ptr->Area() << endl;
    ptr = &s;
    cout << ptr->Area() << endl;
    return 0;
    /*
    If I were to write something like
    Shape sh;
    The compiler would throw an error because Shape is an abstract class. Why? Because it only contains
    pure virtual functions.
    */
}