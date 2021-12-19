#include<iostream>
#include<vector>
using namespace std;

// Function to merge 2 sorted arrays

vector<int> merge(vector<int>first,vector<int>second){

    int n=first.size(),m=second.size();
    vector<int>res(n+m);

    int k=0,i=0,j=0;
    while(i<n && j<m){
        if(first[i] < second[j]){
            res[k]=first[i];
            i++;
            k++;
        }else{
            res[k]=second[j];
            j++;
            k++;
        }
    }

    while(i<n){
        res[k]=first[i];
        k++;
        i++;
    }

    while(j<m){
        res[k]=second[j];
        j++;
        k++;
    }

    return res;
}

int main(){

    int n,m;
    cin>>n;
    vector<int>first(n);
    for(int i=0;i<n;i++)
        cin>>first[i];

    cin>>m;
    vector<int>second(m);
    for(int i=0;i<m;i++)
        cin>>second[i];

    vector<int>res=merge(first,second);

    for(int i=0;i<n+m;i++)
        cout<<res[i]<<" ";

    return 0;
}