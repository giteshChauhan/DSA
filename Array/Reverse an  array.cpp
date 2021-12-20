#include<iostream>
using namespace std;

// Function to reverse an array : Time - O(n)  Space - O(1)

void revArray(int arr[],int start,int end){

    while(start < end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}

// Recursive way 

/*
    void revArray(int arr[],int start,int end){

        if(start >= end)
            return;
        
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;

        revArray(arr,start+1,end-1);
    }
*/

int main(){

    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    revArray(arr,0,n);

    for(int i=0;i<n;i++)
        cout<<arr[i];

    return 0;
}
