#include <iostream>
#include "Test1_Class.h"

using namespace std;
SimDate Date::default_date{};

void f(Date d, const Date cd){
    cout << d.date_rep() << endl;
    cout << cd.date_rep() << endl;
}

int main() {
    //Date today{};
    //Date yesterday{24,6,2015};
    //today.addyear(3).addmonth(2);
    //f(today,yesterday);
    OutterClass Out{};
    Out.Outter_Fun(Out);
    return 0;
}