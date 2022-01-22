#include<iostream>
#include<unordered_set>
using namespace std;

// Function to check whether an array a2[] is a subset of an array a1[] or not.

string isSubset(int a1[],int a2[],int n,int m){

    unordered_set<int>arr1;
    for(int i=0;i<n;i++)
        arr1.insert(a1[i]);

    for(int i=0;i<m;i++)
        if(arr1.find(a2[i]) == arr1.end())
            return "No";

    return "Yes";
}

int main(){
    int n,m;
    cin>>n>>m;
    int a1[n],a2[m];
    for(int i=0;i<n;i++)
        cin>>a1[i];
    for(int i=0;i<m;i++)
        cin>>a2[i];
    cout<<isSubset(a1,a2,n,m);
    return 0;
}