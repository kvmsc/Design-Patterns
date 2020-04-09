/*
    Singleton Pattern in C++
    Used C++17 due to inline feature thet helps for inClass initialization of static variables.
*/ 

#include <bits/stdc++.h>
using namespace std;

class singleton{
    inline static singleton* set = NULL;
    inline static int value = 0;
    singleton(){
        value = 1;
    }

    public:
        static singleton* getInstance(){
            if(set==NULL)
                set = new singleton();
            return set;
        }

        static int getValue(){
            return value;
        }
};


int main(void){
    auto a = singleton::getInstance();
    auto b = singleton::getInstance();
    cout<<a<<endl;
    cout<<b<<endl;
}
