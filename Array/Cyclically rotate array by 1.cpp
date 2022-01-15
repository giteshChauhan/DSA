#include<iostream>
using namespace std;

// Function to rotate its elements clock-wise by one

void rotateByOne(int arr[],int n){
    for(int i=0;i<n;i++){
        int curr=arr[i];
        arr[i]=arr[n-1];
        arr[n-1]=curr;
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    rotateByOne(arr,n);
    for(auto i:arr)
        cout<<i<<" ";
    return 0;
}