//
// Created by Travis Bennet on 19/6/17.
//
#include <iostream>
#include "Basics.h"

using namespace Basics;
using namespace std;

Base1::Base1(double x) :a{},b{},c{},x{x},y{x},z{x}
{
    cout << "Single Double Constructor....." << endl;
}

Base1::Base1(int l, int m, int n) :a{l},b{m},c{n},x{},y{},z{}
{
    cout << "Three Args Constructor....." << endl;
}

int Base1::defaultvalue {100};
char Base1::default2{'x'};
void Base1::change_defaultvalue(int x)
{
    Base1::defaultvalue=x;
    cout << "Default Value Changed To:"<< to_string(x) << endl;
}

//Embedded Class
Base1::Inner::Inner(int x,char y):inner_a{x},inner_ch{y}{cout<<"Construct Inner Class..."<<endl;}
void Base1::Inner::inner_change(int x, char y) {}
//Error,inner class cannot access outter class non-static members without a pointer or reference to outter class object
void Base1::Inner::inner_change2(Base1 & B, int x, char y)
{
    B.a=x;
    B.ch=y;
    cout << "Changing private values of outter class from the inner class..." << endl;
}
//Correct!

void Base1::access_inner()
{
  //  cout << "Access Inner Class Member from Outter Class Function:" << inner_a << inner_ch << endl;
}
void Base1::access_inner2(Inner & IC)
{
    IC.inner_ch='b';
    cout << "Access Inner Class Member from Outter Class Function:" << IC.inner_ch << endl;
}
//Error! Cannot access inner class from outter class

//Construction,Destruction,Copy and Move
Base2::Base2():p{nullptr},s{""},size{0} //Construction order follows the order of the declaration not the implementation
                                        //order
{
    cout << "The default constructor..." << endl;
}

Base2::Base2(string str):s{str},p{nullptr},size{0}
{
    cout << "The single-para string constructor..." << endl;
}

Base2::Base2(int x):s{""},size{x}
{
    p=new double[x];
    cout << "The single-para integer constructor..." << endl;
}

Base2::Base2(string str,int x):s{str},size{x}
{
    p=new double[x];
    cout << "The double-para constructor..." << endl;
}

Base2::~Base2()
{
    if(p){
        delete [] p;
        cout << "Destructing the double list..." << endl;
        if(s!=""){cout << "Destructing the string..." << endl;}
    }
    cout << "Destructor finished" << endl;
}

CoMo::CoMo(int x):size{x},s{""}
{
    ch=new char[size];
    cout << "Single-Para Constructor...." << endl;
}

CoMo::CoMo(int x, string str):size{x},s{str}
{
    ch=new char[size];
    cout << "Double-Para Constructor...." << endl;
}

CoMo::CoMo(std::initializer_list<char> list, string str)
    :s{str}
{
    size=list.size();
    ch=new char[size];
    for (int i=0;i!=size;i++){
        ch[i]=list.begin()[i];
    }
    cout << "Initializer List Constructor..." << endl;
}

CoMo::~CoMo()
{
    if(ch){
        delete [] ch;
        cout << "Destructing the char vector..." << endl;
    }
    cout << "Destruction Completed!!" << endl;
}

CoMo::CoMo(const CoMo & source)
    :size{source.size},s{source.s}
{
    ch=new char[size];
    for (int i=0;i!=size;i++){
        ch[i]=source.ch[i];
    }
    cout << "Deep Copy Construction..." << endl;
}

CoMo& CoMo::operator= (const CoMo & source)
{
    size=source.size;
    s=source.s;
    if(!ch){delete [] ch; cout << "Deleting Target Variable Resource..." << endl;}
    ch=new char[size];
    for (int i=0;i!=size;i++){
        ch[i]=source.ch[i];
    }
    cout << "Deep Copy Assignment..." << endl;
    return *this;
}

void Basics::myprint(CoMo SC){
    cout << "Printing Elements..." << endl;
    cout << "Char Vector Size: " << SC.size << endl;
    cout << "Char Value: " << SC.ch[0] << " at the address: " << static_cast<void*>(SC.ch) << endl;
    cout << "String in SC is: " << SC.s << endl;
}

void Basics::myprint2(CoMo & SC)
{
    cout << "Printing Elements..." << endl;
    cout << "Char Vector Size: " << SC.size << endl;
    cout << "Char Value: " << SC.ch[0] << " at the address: " << static_cast<void*>(SC.ch) << endl;
    cout << "String in SC is: " << SC.s << endl;
}

CoMo::CoMo(CoMo && source)
    :size{source.size},ch{source.ch},s{source.s} //Initialize target object
{
    source.size=0;
    source.ch=nullptr;
    source.s="";
    cout << "Move Constructor..." << endl;
}

CoMo& CoMo:: operator= (CoMo && source){
    if (ch) {delete [] ch; cout << "Cleanup Target Resource..." << endl;} //Cleanup target resource
    //Ordinary Copy Assignment
    size=source.size;
    ch=source.ch;
    s=source.s;
    //Cleanup source object
    source.size=0;
    source.ch=nullptr;
    source.s="";
    cout << "Move Assignment..." << endl;
    return *this;
}
/*
//Another form of Move Assignment
CoMo& CoMo::operator=(CoMo && source) {
    swap(size,source.size);
    swap(ch,source.ch);
    swap(s,source.s);
    cout << "Move Assignment by Swap..." << endl;
    return *this;
}*/

CoMo Basics::MoveTest(CoMo source) {return source;}//Test Return Method
CoMo Basics::MoveTest2(CoMo source) {
    auto tmp=MoveTest(source);
    return tmp;
//    return MoveTest(source);
}