//
// Created by Travis Bennet on 19/6/17.
// This is used to show basic operations of a concrete class.
//

#ifndef CONCRETECLASS_BASICS_H
#define CONCRETECLASS_BASICS_H
#include <string>
using std::string;

namespace Basics{
    class Base1{
    public:
        //Constructors
        Base1(){}; //Default Constructor
        //Constructor Overloading
        explicit Base1(double);
        explicit Base1(int,int,int);
        //Static Test
        static void change_defaultvalue(int);
        static int defaultvalue;
        const static int lala{9};
        static void change2(char x){default2=x;std::cout<<"Change default value"<<std::endl;}
        void access(){std::cout<<"Access default static int:"<<a<<std::endl;}
        //Embedded Class
        class Inner{
        private:
            int inner_a;
        public:
            char inner_ch;
            Inner(){};
            explicit Inner(int, char);
            void inner_change(int, char);//Cannot access non-static members in outter class
            static void inner_change2(Base1 &, int, char);
            //Can access non-static members in outter class and must be static
        };
        void access_inner();
        void access_inner2(Inner &);
    private:
        int a,b,c; //Members
        double x,y,z;
        char ch;
        static char default2;//Static Test
    };

    //Construction,Destruction,Copy and Move
    class Base2{
    public:
        Base2(); //Default Constructor
        Base2(string);
        Base2(int);
        Base2(string,int);
        ~Base2();//Destructor
    private:
        string s;
        double * p;
        int size;
       // ~Base2();//Making Destructor private prevents destruction
    };

    //Initialization without constructors
    class Init_nonCons{
    public:
        string s;
        int t;
        char * p;
        //Init_nonCons(){}//Default Construction
        //Init_nonCons(const Init_nonCons &);//Copy Construction
    };

    //Initialization with constructors
    //See Base2

    //Initialization with default constructors
    class Init_Default{
    public:
        int t;
        Init_Default(int t=10){} //Single argument with a default value can act as a default constructor
    };

    //Initializer_list Constructor
    class Init_list{
    public:
        char * ch;
        Init_list(std::initializer_list<char> list){
            ch=new char[list.size()];
            for (int i=0; i!=list.size(); i++){
                *(ch+i)=list.begin()[i];}
        }
        Init_list():ch{nullptr}{}
        ~Init_list(){delete [] ch;}
    };
}
#endif //CONCRETECLASS_BASICS_H
