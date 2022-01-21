#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// Function to find the maximum product subarray ( using kadane's algorithm)

long long maxProduct(vector<int>arr,int n){

    long long maxPro=1,minPro=1,ans=INT_MIN;
    for(int i=0;i<n;i++){
        long long curr=arr[i];
        if(curr < 0)
            swap(maxPro,minPro);
        maxPro=max(curr,curr*maxPro);
        minPro=min(curr,curr*minPro);
        ans=max(ans,maxPro);
    }

    return ans;
}

int main(){

    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<maxProduct(arr,n);
    return 0;
}