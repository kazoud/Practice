#include <iostream>
#include <memory>
using namespace std;

/*
Smart pointers allow us to not worry about the deletion of our allocated objects.
There are several types of smart pointers, here we explore the unique_ptr and the shared_ptr.
*/

int main()
{

// unique_ptr
// We use a unique_ptr when we only want one pointer to point to our object:

    unique_ptr<int> uniquePtr(new int);
    *uniquePtr = 7;
    cout << *uniquePtr << endl; //prints 7

    /*
    unique_ptr<int> secondPtr = uniquePtr;
    This statement does not compile.
    */

    //To transfer ownership to a new pointer:
    unique_ptr<int> secondPtr = move(uniquePtr);
    cout << *secondPtr << endl; //prints 7

    /*
    cout << *uniquePtr << endl;
    The variable uniquePtr does not have ownership of the object anymore.
    If I try to access it with the above statement, I get a segmentation fault.
    */

//shared_ptr
    shared_ptr<int> sharedPtr(new int(52));
    cout << *sharedPtr << endl;

    shared_ptr<int> alsoShared = sharedPtr; //This time, code compiles without problem
    cout << *alsoShared << endl;
    cout << sharedPtr.use_count() << endl << alsoShared.use_count() << endl; 
    //We call the use_count() function to keep track of how many pointers share the object.
    
    return 0;
}