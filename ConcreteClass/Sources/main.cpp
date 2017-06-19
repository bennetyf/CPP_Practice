#include <iostream>
#include "Basics.h"

using namespace std;
using namespace Basics;

void fun(const Base1 & tmp){}

int main() {
    /*
    explicit关键字测试
    Base1 A{1};
    Base1 B=Base1{2};
    Base1 C={3,4,5};
    //Base1 D=4.0;
    fun({7,8,9});
    */

    /*Static关键字测试
    Base1 A{1,2,3};
    Base1 B{4,5,6};
    cout << "Access by object:" << A.defaultvalue <<
         "\tAccess by class:" << Base1::defaultvalue << endl;//Static Member can be accessed through object or class
    A.change_defaultvalue(10);
    cout << B.defaultvalue << endl;
    B.access();
    */

    /* Inner Class测试
    Base1 A{1,2,3};
    Base1::Inner::inner_change2(A,200,'w');
    A.access();
    Base1::Inner B{10,'c'};
    A.access_inner2(B);
    */

    /* Constructor and Destructor
    Base2 A{}; //Default Initialization
    Base2 *B=new Base2{"CCCCCC"}; //Single String Initialization
    Base2 C{10}; //Single Int Init
    Base2 D{"This is a String",20};//
    delete B;
    */

    /*Initialization
    //Init_nonCons A; //Don't use initializers (on local variable)
    static Init_nonCons A;  //Don't use initialization (on static or global variables)
    cout << "No Initializer: " << A.s << " and " << A.t << endl;

    Init_nonCons B{};       //Using default initialization
    cout << "Default Initializer: " << B.s << " and " << B.t << endl;

    char * ch=new char{'a'};
    cout << "The address of " << ch << " is: " << static_cast<void*>(ch) << endl;

    Init_nonCons C{"Bennet",100, ch};   //Memberwise initialization of public members(shallow copy)
    cout << "Member-wise Initializer: " << C.s << " and " << C.t << " and "
         << static_cast<void*>(C.p) << endl;

    Init_nonCons D{C};  //Using copy initialization (default copy constructor,still shallow copy)
    cout << "Copy Initializer: " << D.s << " and " << D.t << " and "
         << static_cast<void*>(D.p) <<endl;
    delete ch;
    */
    /*Default constructor
    Init_Default A{};
    cout << "Default Initialization: " << A.t << endl;
    */

    ///*Initializer_list Constructor
    Init_list A{'a','b','c','d'};
    cout << "Initializer list : " << *A.ch << endl;
    Init_list B={'e','f'};
    cout << "Initializer list : " << B.ch[1œ] << endl;
    return 0;
}//On exiting the main function scope,destructors are called in the reverse order.