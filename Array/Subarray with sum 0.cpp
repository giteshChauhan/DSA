#include<iostream>
#include<unordered_map>
using namespace std;

// Function to return true if subarray with sum 0 exists , false otherwise.

bool subArrayExists(int arr[],int n){

    unordered_map<int,int>mp;
    int sum=0;
    for(int i=0;i<n;i++){
        if((sum+=arr[i]) == 0 || (mp.find(sum) != mp.end()))
            return true;
        mp[sum]++;
    }

    return false;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<subArrayExists(arr,n);
    return 0;
}