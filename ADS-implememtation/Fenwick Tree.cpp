#include<iostream>
using namespace std;

void createBIT(int arr[],int BIT[],int size){
    while(int i=0;i<size-1;i++){
        updateBIT(i,arr[i],BIT,size);
    }
}

void updateBIT(int index,int incval,int BIT[],int size){
    index++;
    while(index < size){
        BIT[index] += incval;
        index += (index & (-index));//get all the next nodes in the tree which will reflect the change
    }
}

int getPrefixSum(int index,int BIT[]){
    int sum = 0;
    index++;
    while(index > 0){
        sum += BIT[index];
        index = index & (index-1);//get parent 
    }
    return sum;
}

int main(){
    cout<<"Enter the number of elements in the array: ";
    int n;
    cin>>n;
    cout<<"Enter "<<n<<" elements:"<<endl;
    int arr[n],BIT[n+1] = {0};
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    create(arr,BIT,n+1);
    cout<<"Enter any valid index to obtain prefix sum: ";
    int i;
    cin>>i;
    if(i <= n) cout<<"Prefix sum is:"<<getPrefixSum(i-1,BIT)<<endl;
    else cout<<"Invalid index.";
    return 0;
}