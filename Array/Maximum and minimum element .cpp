#include<iostream>
using namespace std;

// Function to find the maximum and minimum element in an array

pair<long long,long long> getMinMax(long long a[],int n){

    pair<long long,long long>p;
    p.first=p.second=a[0];

    for(int i=1;i<n;i++){
        if(a[i] < p.first)
            p.first=a[i];
        if(a[i] > p.second)
            p.second=a[i];
    }

    return p;
}


int main(){

    int n;
    cin>>n;
    long long a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    pair<long long,long long>p=getMinMax(a,n);

    cout<<p.first<<" "<<p.second;

    return 0;
}