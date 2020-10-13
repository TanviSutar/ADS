//https://www.codechef.com/problems/JABO
#include<iostream>
#include<map>
#define loop(s,e,i,sj,j) for(int i=s,j=sj;i<e;i++,j++)
#define loop2(i,n) for(int i=0;i<n;i++)
using namespace std;

map<char,int> mapp;
map<int,int> parent;
map<int,int> status;
map<int,int> ranks;

int char_coordinate_decode(char c1,char c2){
    //cout<<mapp[c1]<<" "<<mapp[c2]<<" "<<52*mapp[c1]+mapp[c2];
    return 52*mapp[c1]+mapp[c2];
}

int map_grp(int r,int c){
    if(c%5 == 0) c = int(c/5)-1;
    else c = int(c/5);
    return r+(c*5);
}

int my_find(int val){
    if(parent[val] == val) return val;
    return parent[val] = my_find(parent[val]);
}

void my_union(int val1,int val2){
    int p1 = my_find(val1);
    int p2 = my_find(val2);

    //union by rank, in this case union by status
    if(p1 == p2) return;
    if(ranks[p1] > ranks[p2]){
        parent[p2] = p1;
        status[p1] += status[p2];
    }
    else if(status[p1] < status[p2]){
        parent[p1] = p2;
        status[p2] += status[p1];
    }
}

void give_voltage(int val){
    int p = my_find(val);
    status[p]++;
}

void remove_voltage(int val){
    int p = my_find(val);
    status[p]--;
}

void led_status(int val1,int val2){
    //cout<<"inledfunc\n";
    int p1 = my_find(val1);
    //cout<<p1<<" got p1\n";
    int p2 = my_find(val2);
    //cout<<p2<<" got p2\n";
    //cout<<p1<<" "<<status[p1]<<" "<<p2<<" "<<status[p2]<<endl;
    if((status[p1] == 0 and status[p2] >= 1) or (status[p2] == 0 and status[p1] >= 1))
        cout<<"ON\n";
    else cout<<"OFF\n";
}

int main(){
    //creating the character mapping map
    loop(65,91,i,0,j) mapp[char(i)] = j;
    loop(97,123,i,26,j) mapp[char(i)] = j;

    int n,r,c;
    char ch;
    cin>>n>>r>>c;

    for(int i=1;i<=r*c;i++){
        parent[i] = i;
        status[i] = 0;
        ranks[i] = 0;
    }
    //debug
    //for(auto i:parent) cout<<i.first<<" "<<i.second<<endl;
    //for(auto i:status) cout<<i.first<<" "<<i.second<<endl;

    char arr[8];
    int cord[4],tmp,p1,p2;
    loop2(i,n) {
        cin>>ch;
        if(ch == 'W' or ch == 'L'){
            loop2(i,8) cin>>arr[i];
            tmp = 0;
            //cout<<"in\n";
            loop2(i,4) {
                //cout<<i<<endl;
               cord[i] = char_coordinate_decode(arr[tmp],arr[tmp+1]);
               //cout<<cord[i]<<" ";
               tmp += 2;
            }
            //cout<<"out\n";
            //loop2(i,4) cout<<cord[i]<<" ";//print
            if(ch == 'W'){
                p1 = map_grp(cord[0],cord[1]);
                p2 = map_grp(cord[2],cord[3]);
                my_union(p1,p2);
            }
            else{
                //cout<<"in else\n";
                p1 = map_grp(cord[0],cord[1]);
                //cout<<p1<<"through1\n";
                p2 = map_grp(cord[2],cord[3]);
                //cout<<p2<<" through 2\n";
                led_status(p1,p2);
                //cout<<"end\n";
            }
        }
        if(ch == 'V' or ch == 'R'){
            loop2(i,4) cin>>arr[i];
            tmp = 0;
            loop2(i,2) {
               cord[i] = char_coordinate_decode(arr[tmp],arr[tmp+1]);
               tmp += 2;
            }
            //loop2(i,2) cout<<cord[i]<<" ";//print
            if(ch == 'V'){
                p1 = map_grp(cord[0],cord[1]);
                give_voltage(p1);
            }
            else{
                p1 = map_grp(cord[0],cord[1]);
                remove_voltage(p1);
            }
        }
    }
    cout<<endl;
    return 0;
}