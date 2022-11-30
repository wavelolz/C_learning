#include <iostream>
#include <algorithm>
#include <utility>
#include <bits\stdc++.h>
using namespace std;


// To initialize the class
class c1{
    public:
        int num;
        string str;
};

// To declare method inside the class
class c2{
public:
    void func(){
        cout << "hello" << endl;
    };
    int func2(int a, int b);

};

// We can also initialize function outside the class, but note that it has to be
// first declare in the class
int c2::func2(int a, int b){
    return a + b;
}


// We can add constructor to the class. It always has same name with the class.
// And will be called when instance of class is created. Note that it does not
// has return value. Its main goal is to set the default value for attributes
// in class

class c3{
public:
    int val_a, val_b, val_c;
    c3(int a, int b, int c) {
        cout << "Constructor is created" << endl; // This is the constructor
        val_a = a; // Initialize default value
        val_b = b;
        val_c = c;
    }
};

// Constructor could also be declare inside function and then initialize
// outside function
class c4{
public:
    int val_a, val_b, val_c;
    c4(int a, int b, int c);
};

c4::c4(int a, int b, int c){
    val_a = a;
    val_b = b;
    val_c = c;
}

// Access Specifier:
// There are three kinds of access specifier
// 1. public: members could be viewed and modified outside class
// 2. private: members could not be accessed outside class
// 3. protected: members could not be accessed outside class, but it could be accessed in inherited class
// If one don't put access specifier, then the attribute will be treated as private
class c5{
public:
    int x;
private:
    int y;
};

// If one want to view or modify private attribute, getter and setter function has to
// be declared in public. This is called Encapsulation
class c6{
private:
    int val_y;
public:
    int getter(){
        return val_y;
    }
    void setter(int y){
        val_y = y;
    }

};

// Inheritance
// We could inherit attributes and methods from base class
class c7base{
public:
    string type;
    void gettype(){
        cout << "The type of this food is: " << type << endl;
    }
};

class c7child: public c7base{
public:
    string color;
    void getcolor(){
        cout << "The color of " << type << " is " << color;
    }
};

// MultiLayer Inheritance
// We could inherit multiple class
class c8grand{
public:
    int gint;
};

class c8parent: public c8grand{
public:
    int pint;
};

class c8child: public c8parent{
public:
    int cint;
};


int main(){
    c8child fc;
    fc.gint = 0;
    fc.pint = 1;
    fc.cint = 2;


    /* c7

    c7child fc;
    fc.color = "green";
    fc.type = "fruit";
    fc.gettype();
    fc.getcolor();
    */
    /* c6

    c6 fc;
    fc.setter(3);
    cout << fc.getter() << endl;
    */
    /* c5

    c5 fc;
    fc.x = 1;
    fc.y = 2;
    */
    /* c4

    c4 fc(1, 2, 3);
    cout << fc.val_a << endl;
    cout << fc.val_b << endl;
    cout << fc.val_c << endl;
    */


    /* c3

    c3 fc(1, 2, 3);
    cout << fc.val_a << endl;
    cout << fc.val_b << endl;
    cout << fc.val_c << endl;
    */


    /* c2

    c2 fc;
    fc.func();
    int result = fc.func2(1, 3);
    cout << result;
    */


    /* c1

    c1 fc;
    fc.num = 1;
    fc.str = "hello class";
    cout << fc.num << endl;
    cout << fc.str << endl;

    */




}
