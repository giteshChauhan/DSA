#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

// Function to find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers,
// the consecutive numbers can be in any order.

int findLongestConsecSubseq(int arr[],int n){

    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
        mp[arr[i]];
    
    int ans=0;
    for(int i=0;i<n;i++){
        if(mp.find(arr[i] - 1) == mp.end()){
            int count=arr[i];
            while(mp.find(count) != mp.end())
                count++;
            ans=max(ans,count - arr[i]);
        }
    }

    return ans;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<findLongestConsecSubseq(arr,n);
    return 0;
}