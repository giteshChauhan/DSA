#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/* Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet.
   Each packet can have a variable number of chocolates. There are M students, the task is to distribute chocolate packets
   among M students such that :

    1. Each student gets exactly one packet.
    2. The difference between maximum number of chocolates given to a student and minimum number of chocolates 
        given to a student is minimum.
*/

long long findMinDiff(vector<long long>a,long long n,long long m){

    sort(a.begin(),a.end());

    long long i=0,j=m-1,ans=INT_MAX;
    while(j < n){
        ans=min(a[j] - a[i],ans);
        i++;
        j++;
    }

    return ans;
}

int main(){
    long long n,m;
    cin>>n>>m;
    vector<long long>a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    cout<<findMinDiff(a,n,m);
    return 0;
}