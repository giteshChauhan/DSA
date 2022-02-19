#include<iostream>
#include<algorithm>
using namespace std;

// Function to find the size of smallest subarray whose sum is greater than a given value.

// 1) If numbers are positive only :

int smallestSubWithSum(int arr[],int n,int x){
    
    int currSum=0,end=0,start=0,minLen=INT_MAX;
    while(end < n){
        while(currSum <= x && end < n)
            currSum+=arr[end++];

        while(currSum > x && start < n){
            if(end - start < minLen)
                minLen=end - start;
            
            currSum-=arr[start++];
        }
    }

    return minLen;
}

int main(){
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<smallestSubWithSum(arr,n,x);
    return 0;
}