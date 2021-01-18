//You are given a string. You have to find the smallest substring which contains all the characters of given string. Solve it in O(n), and sliding window technique.

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void func(string str, string pat){
    int ascii_str[256] = {0};
    int ascii_pat[256] = {0};
    for(int i=0;i<pat.size();i++) ascii_pat[pat.at(i)]++;
    int minim = str.size(), strt = -1, end = -1, cnt = 0, i = 0, s = -1;
    while(i < str.size()){
        char chr = str.at(i);
        if(ascii_pat[chr] == 0){
            i++;
            continue;
        } //unnecessary characters

        ascii_str[chr]++;
        if(s == -1) s = i;
        if(cnt < pat.size() and ascii_str[chr] <= ascii_pat[chr]) cnt++;
        
        if(cnt >= pat.size()){
            while((ascii_pat[str.at(s)] == 0 or ascii_str[str.at(s)] > ascii_pat[str.at(s)])){
                if(ascii_str[str.at(s)] > ascii_pat[str.at(s)]) ascii_str[str.at(s)]--;
                s++;
            }
            if(minim > (i-s+1)){
                minim = i-s+1;
                strt = s;
                end = i;
            }
        }
        i++;
    }
    
    for(int i=strt; i <= end; i++) cout<<str.at(i);cout<<endl;
}

int main(){
    string str = "geeksfor geeks";
    string pat = "ork";
    func(str,pat);
    return 0;
}