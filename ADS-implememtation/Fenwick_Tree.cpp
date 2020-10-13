#include<iostream>
using namespace std;

void updateBIT(int index,int incval,int BIT[],int size){
    index++;
    while(index < size){
        BIT[index] += incval;
        index += (index & (-index));//get all the next nodes in the tree which will reflect the change
    }
}

void createBIT(int arr[],int BIT[],int size){
    for(int i=0;i<size-1;i++){
        updateBIT(i,arr[i],BIT,size);
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
    createBIT(arr,BIT,n+1);
    cout<<"Enter any valid index to obtain prefix sum(enter -1 to exit): ";
    int i;
    do{
    cin>>i;
    if(i >= 1 and i <= n) cout<<"Prefix sum is:"<<getPrefixSum(i-1,BIT)<<endl;
    else cout<<"Invalid index/exit value\n";
    }while(i!=-1);
    return 0;
}