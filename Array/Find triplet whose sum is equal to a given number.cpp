#include<iostream>
#include<algorithm>
using namespace std;

// Function to find whether there exists any triplet in array whose sum is equal to a given number.

bool find3Numbers(int arr[],int n,int X){

    sort(arr,arr+n);

    for(int i=0;i<n;i++){
        int x=X-arr[i],j=i+1,k=n-1;
        while(j < k){
            int sum=arr[j] + arr[k];
            if(sum == x)
                return true;
            else if(sum > x)
                k--;
            else j++;
        }
    }

    return false;
}

int main(){
    int n,X;
    cin>>n>>X;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<find3Numbers(arr,n,X);
    return 0;
}