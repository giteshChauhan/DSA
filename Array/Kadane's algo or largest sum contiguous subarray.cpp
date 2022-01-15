#include<iostream>
#include<algorithm>
using namespace std;

// Function to find largest sum contiguous subarray using Kadane's algorithm

long long maxSubarraySum(int arr[],int n){

    long long currMax=0,overMax=INT_MIN;
    for(int i=0;i<n;i++){
        currMax=max(currMax+arr[i],(long long)arr[i]);
        overMax=max(overMax,currMax);
    }

    return overMax;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<maxSubarraySum(arr,n);
    return 0;
}