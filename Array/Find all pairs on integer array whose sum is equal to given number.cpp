#include<iostream>
#include<unordered_map>
using namespace std;

// Function to count the number of pairs in an array whose sum is equal to given number k.

int getPairsCount(int arr[],int n,int k){

    int count=0;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
        mp[arr[i]]++;
    
    for(int i=0;i<n;i++){
        if(mp[k-arr[i]] > 0){
            mp[arr[i]]--;
            count+=mp[k-arr[i]];
        }
    }

    return count;
}

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<getPairsCount(arr,n,k);
    return 0;
}