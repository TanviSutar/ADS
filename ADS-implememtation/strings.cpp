#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main(){
    //2 ways of implementing strings: 
    //1. character array
    //2. string

    //1. character array
    
    //initialization
    //char arr[] = {'B','u','r','g','e','r'};
    char arr[] = "Burger";

    //traverse 
    for(int i=0;i<6;i++) cout<<arr[i];

    //builtin functions for strings

    //strlen: returns the length of the character string
    cout<<strlen(arr)<<endl;

    //strcpy: copy the contents of string
    char arr2[10];
    strcpy(arr2,arr);
    cout<<arr2<<endl;//burger

    //strcat: append one string to another
    char chararr[10] = "ice";
    strcat(chararr,"cream");
    cout<<chararr<<endl;//icecream

    //2. string 
    string str = "Burger";


    //buitlin functions

    //size
    cout<<str.size()<<endl;

    //substr
    cout<<str.substr(1,4); //urge

    //append
    str.append(" shop");
    cout<<str<<endl;



    return 0;
}