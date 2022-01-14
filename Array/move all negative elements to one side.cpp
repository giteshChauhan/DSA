#include<iostream>
using namespace std;


// Function to move all negative elements to one side of an array.
// Note : Order of elements is not maintained

void swap(int &i,int &j){
    int temp=i;
    i=j;
    j=temp;
}

void rearrange(int arr[],int n){
    int j=0;
    for(int i=0;i < n;i++){
        if(arr[i] < 0){
            if(i != j)
                swap(arr[i],arr[j]);
            j++;
        }
    }
}

int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    rearrange(arr,n);
    for(auto i:arr)
        cout<<i<<" ";

    return 0;
}
