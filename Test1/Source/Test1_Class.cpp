//
// Created by Travis Bennet on 16/6/17.
//

#include "Test1_Class.h"
#include <iostream>
using std::to_string;
using std::string;

Date::Date(int dd, int mm, int yy)
        :cache_valid{false},cache{""}
{
    d=dd?dd:default_date.d;
    m=mm?mm:default_date.m;
    y=yy?yy:default_date.y;
}

Date& Date::addyear(int n) {
    y+=n;
    return *this;
}

Date& Date::addmonth(int n) {
    m+=n;
    return *this;
}

Date& Date::addday(int n) {
    d+=n;
    return *this;
}

string Date::date_rep() const {
    if(!cache_valid) {
        cache=to_string(d)+"/"+to_string(m)+"/"+to_string(y);
        cache_valid=true;
    }
    return cache;
}

int Date::year() const {
    return y;
}

int Date::month() const {
    return m;
}

int Date::day() const {
    return d;
}

void Date::set_default_date(int dd, int mm, int yy) {
    default_date.d=dd;
    default_date.m=mm;
    default_date.y=yy;
}

void OutterClass::Op_Outter() {
   // a=1000; //Error! Cannot access inner class member from the outter class
   // b=2000; //Error!
   // std::cout << "This is from Op_Outter:" << a << std::endl;
}

void OutterClass::InnerClass::Op_Inner(OutterClass& Outter) {
    //A=2;  // Error! Cannot access non-static outter class member, because inner class doesn't
            // have access to the outter class object
    Outter.A=20; //Correct!
    Outter.B=3;
    std::cout << "This is from Op_Inner:" << Outter.A <<std::endl;
}

void OutterClass::Outter_Fun(OutterClass& Outter) {
    InnerClass Inner{};
    Inner.Op_Inner(Outter);
}