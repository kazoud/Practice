#include <iostream>
using namespace std;

/*
A template is a function or a class that we parametrize with a set of types or values.
*/



/*
Parametrized types: We can have a vector of any type we want
*/
template<typename T>

class Vector{
private:
    int size;
    T* elems;

public:
    Vector(int s){
        size = s;
        elems = new T[size];
    }
    ~Vector() 
    {
        delete[] elems;
    }
};

/*
Function templates: We can use templates for functions as well. In the below example, defining
the GreaterThan function that way allows us to use it for many types.
*/
template<typename T>

T GetMax(T a, T b)
{
    return (a > b)?a:b ;
}

/*
Function objects (aka functors) : We can define objects that can be called like functions.
*/
template<typename T>
class LessThan{
    const T val;
    public:
    LessThan(const T& v) : val(v) {}
    bool operator() (const T& x) { return x < val;}
};


int main()
{
    //Parametrized types:
    Vector<double> doubles(5);
    Vector<char> chars(200);

    //Function templates:
    cout << GetMax(4,8) << endl;
    cout << GetMax('n', 'q') << endl;
    cout << GetMax(5.6, 178.9) << endl;

    //Function objects (functors):
    LessThan<int> lt(500);
    bool b = lt(600);
    cout << lt(367) << endl << b << endl;
    return 0;
}