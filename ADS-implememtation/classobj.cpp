#include<bits/stdc++.h>
using namespace std;


/*

access specifiers

private: highly secure/protected, data can be accessed only within the class
protected: second highly secured, data can be accessed within the class and subclass
public: least security, data is available everywhere

*/


//class definition
class Myclass{
    private:
        int privatevar = 10;
    protected:
        int protectedvar = 20;

    public:
        int publicvar = 30;

        void func(){
            cout<<"Hello world..."<<endl;
        }
};

//derived class of Myclass
class child: Myclass{
    public:
        void function(){
            //accessing parent class variable
            cout<<"(In child)Parent class protected variable: "<<protectedvar<<endl;
            cout<<"(In child)Parent class public variable: "<<publicvar<<endl;

            //trying to access private variable of parent class gives error
            //cout<<"(In child)Myclass private variable: "<<privatevar<<endl;
        }
};

int main(){
    Myclass obj;
    
    //acessing public variable and functions of Myclass
    cout<<"(In main)Myclass public variable: "<<obj.publicvar<<endl;
    obj.func();

    //trying to access private or protected variable of Myclass gives error
    /* cout<<"(In main)Myclass protected variable: "<<obj.protectedvar<<endl;
    cout<<"(In main)Myclass private variable: "<<obj.privatevar<<endl; */
    
}