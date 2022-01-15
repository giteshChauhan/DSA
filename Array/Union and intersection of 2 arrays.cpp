#include<iostream>
#include<set>
#include<map>
using namespace std;

// Functions to find number of elements in union and intersection of 2 arrays.

int doUnion(int a[],int n,int b[],int m){

    set<int>s;
    for(int i=0;i<n;i++)
        s.insert(a[i]);
    for(int j=0;j<m;j++)
        s.insert(b[j]);
    
    return s.size();
}

int doIntersection(int a[],int n,int b[],int m){
    map<int,int>mp;
    int count=0;
    for(int i=0;i<n;i++)
        mp[a[i]]=i;
    for(int j=0;j<m;j++){
        if(mp.find(b[j]) != mp.end()){
            mp.erase(b[j]);
            count++;
        }
    }
        
    return count;
}

int main(){
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int j=0;j<m;j++)
        cin>>b[j];
    cout<<doUnion(a,n,b,m)<<endl;
    cout<<doIntersection(a,n,b,m)<<endl;
    return 0;
}