//https://www.spoj.com/problems/GSS1/
//http://strangeonehere.blogspot.com/2018/03/spoj-gss1.html : refer this for code explaination
#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#define MIN_VAL -15007
using namespace std;

class node{
    public:
        int maxpfx;
        int maxsfx;
        int sum;
        int max;
        node(){}
        node(int mp,int ms,int s,int m){
            this->maxpfx = mp;
            this->maxsfx = ms;
            this->sum = s;
            this->max = m;
        }
        node(const node &n){
            maxpfx = n.maxpfx;
            maxsfx = n.maxsfx;
            sum = n.sum;
            max = n.max;
        }
};

int powof2(int n){
    for(int i=0;i<n;i++)
        if(pow(2,i) >= n) return 2*pow(2,i)-1;
    return -1;
}

void constructStree(vector<int> vec,vector<node> &stree,int low,int high,int pos){
    if(low == high){
        stree[pos] = node(vec[low],vec[low],vec[low],vec[low]);
        return;
    }
    int mid = (low+high)/2;
    constructStree(vec,stree,low,mid,pos*2+1);
    constructStree(vec,stree,mid+1,high,pos*2+2);
    node lft(stree[pos*2+1]);
    node rght(stree[pos*2+2]);
    int mpf = std::max(lft.maxpfx,lft.sum+rght.maxpfx);
    int msf = std::max(rght.maxsfx,rght.sum+lft.maxsfx);
    int s = lft.sum + rght.sum;
    int m = std::max(std::max(lft.max,rght.max),lft.maxsfx+rght.maxpfx);
    stree[pos] = node(mpf,msf,s,m);
}

void print(vector<node> stree){
    int j=0;
    for(auto i:stree){
        cout<<j<<": "<<i.maxpfx<<" "<<i.maxsfx<<" "<<i.sum<<" "<<i.max<<endl;
        j++;
    }
}

node * rmq(vector<node> stree,int qlow,int qhigh,int low,int high,int pos){
    if(qlow > high or qhigh < low or low > high) return NULL;
    if(qlow <= low and qhigh >= high){
        node *n = &stree[pos];
        return n;
    }
    int mid = (low+high)/2;
    node *n1 = rmq(stree,qlow,qhigh,low,mid,pos*2+1);
    node *n2 = rmq(stree,qlow,qhigh,mid+1,high,pos*2+2);
    if(n1 == NULL and n2 == NULL) return NULL;
    else if(n1 == NULL) return n2;
    else if(n2 == NULL) return n1;
    node *n = new node();
    n->maxpfx = std::max(n1->maxpfx,n1->sum+n2->maxpfx);
    n->maxsfx = std::max(n2->maxsfx,n2->sum+n1->maxsfx);
    n->sum = n1->sum+n2->sum;
    n->max = std::max(std::max(n1->maxpfx,n2->maxsfx),n1->maxsfx+n2->maxpfx);
    return n;
}

int main(){
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n,tmp;
    int m,x,y;
    cin>>n;
    vector<int> vec;
    vector<node> stree;
    for(int i=0;i<n;i++){
        cin>>tmp;
        vec.push_back(tmp);
    }
    node obj1(MIN_VAL,MIN_VAL,MIN_VAL,MIN_VAL);
    for(int i=0;i<powof2(n);i++) stree.push_back(obj1);
    /*cout<<"initilization\n";
    print(stree);*/
    constructStree(vec,stree,0,n-1,0);
    /*cout<<"Construction\n";
    print(stree);
    cout<<"Enter m:";*/
    cin>>m;
    node *obj = NULL;
    while(m--){
        cin>>x>>y;
        if(x<0) x = 1;
        if(y>n) y = n;
        obj = rmq(stree,x-1,y-1,0,n-1,0);
        if(obj != NULL)cout<<obj->max<<endl;
    }
    return 0;
}



/* Code explaination
Here’s my attempt at explaining the approach. The problem is the maximum sum subarray problem, which you want to solve by a divide and conquer approach, which is what a segment tree does.

For a given range AA, you split it into two pieces, the left half LL and the right half RR. Naturally the maximum sum subarray in AA can lie either 1) completely in LL, or lie 2) completely in RR, or 3) cross over from LL to RR. Solve recursively for the two halves. We get the maximum sum subarrays for the left half as L.maxsumL.maxsum and the right half as R.maxsumR.maxsum, and now we know the first 2 of the 3 options just like that *snaps fingers* :stuck_out_tongue:
How do we get the third option? A range that extends from LL to RR can be broken into a suffix of LL and a prefix of RR. So if we know the maximum suffix sum in LL as L.suffixsumL.suffixsum and the maximum prefix sum in RR as R.prefixsumR.prefixsum, the sum of those 2 values will give us the maximum sum subarray extending from LL to RR, which covers option 3. So we get

tree[index].maxsum = max(max(tree[2\*index+1].maxsum, tree[2\*index+2].maxsum),
                     tree[2\*index+1].suffixsum + tree[2\*index+2].prefixsum);
Now since we have incorporated 2 new values (prefixsum and suffixsum), the parent range of AA will also require these from AA. So now we need to calculate A.prefixsumA.prefixsum and A.suffixsumA.suffixsum. The maximum sum prefix of AA can be 1) the maximum sum prefix of LL, or 2) cover the whole of LL and extend into RR. Option 1 is simply L.prefixsumL.prefixsum, and option 2 is \sum L + R.prefixsum∑L+R.prefixsum. Similarly, the maximum sum suffix of AA is either R.suffixsumR.suffixsum or \sum R + L.suffixsum∑R+L.suffixsum. So now it seems we need another value to represent a range, which is the sum of that range. So we have

tree[index].prefixsum = max(tree[2\*index+1].prefixsum,
                        tree[2\*index+1].sum + tree[2\*index+2].prefixsum);
tree[index].suffixsum = max(tree[2\*index+2].suffixsum,
                        tree[2\*index+2].sum + tree[2\*index+1].suffixsum);
And for the sum it is simply

tree[index].sum = tree[2\*index+1].sum + tree[2\*index+2].sum;
Well, that covers the whole thing, I hope it is clear why we require the 4 values in one node of the segment tree. Also you can see that the calculation of tree[index].maxsum in the link you provided can be simplified as I have described above. Feel free to ask if anything is not clear*/