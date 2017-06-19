//
// Created by Travis Bennet on 16/6/17.
//

#ifndef TEST1_TEST1_CLASS_H
#define TEST1_TEST1_CLASS_H

#include <string>

struct SimDate{
    SimDate():d{10},m{10},y{1770}{}
    int d,m,y;
};

class Date{
private:
    int d,m,y;
    mutable bool cache_valid;
    mutable std::string cache;
    static SimDate default_date;

public:
    explicit Date(int=0,int=0,int=0);

    Date& addyear(int);
    Date& addmonth(int);
    Date& addday(int);

    int year() const ;
    int month()const ;
    int day() const ;

    std::string date_rep() const;

    static void set_default_date(int,int,int);
};

class OutterClass{
private:
    int A,B;
    class InnerClass{
    private:
        int a,b;
    public:
        void Op_Inner(OutterClass&);
    };
public:
    OutterClass():A{0},B{1}{}
    ~OutterClass(){}
    void Op_Outter();
    void Outter_Fun(OutterClass&);
};
#endif //TEST1_TEST1_CLASS_H
