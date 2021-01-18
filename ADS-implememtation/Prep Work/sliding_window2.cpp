////You are given a string. You have to find the smallest substring which contains all the characters of given string. Solve it in O(n), and sliding window technique.

#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

void getWindow(string str,string ptr){
    int strlen = str.size();
    int ptrlen = ptr.size();
    int len = 0;

    if(strlen < ptrlen){
        cout<<"Not possible\n";
        return;
    }

    int ascii_str[256] = {0};
    int ascii_ptr[256] = {0};

    for(int i=0;i<ptrlen;i++){
        if(ascii_ptr[ptr.at(i)] == 0){
            ascii_ptr[ptr.at(i)] = 1;
            len++;
        }
    } 

    int cnt = 0, strt = -1, end = -1, minim = strlen, s = -1;

    for(int i=0;i<strlen;i++){
        char chri = str.at(i);
        if(ascii_ptr[chri] == 0) continue;
        ascii_str[chri]++;
        if(s == -1) s = i;
        if(cnt < len and ascii_str[chri] <= ascii_ptr[chri]) cnt++;

        if(ascii_str[chri] > ascii_ptr[chri] and str.at(s) == chri){
            while((ascii_str[str.at(s)] > ascii_ptr[str.at(s)] or ascii_ptr[str.at(s)] == 0) and s < i){
                if(ascii_str[str.at(s)] > ascii_ptr[str.at(s)]) ascii_str[str.at(s)]--;
                s++;
            }
        }
        if(cnt >= len and minim > (i-s+1)){
            minim = i-s+1;
            strt = s;
            end = i;
        }
    }
    for(int i=strt,j=1;j<=minim;i++,j++) cout<<str.at(i);
    cout<<endl;
}

int main(){
    string str = "this  is test string";
    string ptr = "tissiitr";
    getWindow(str,ptr);
    return 0;
}