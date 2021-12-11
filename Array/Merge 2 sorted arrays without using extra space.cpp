#include<iostream>
using namespace std;

void merge(int[],int[],int,int);

int main(){

    int n,m;
    cin>>n>>m;
    int arr1[n],arr2[m];
    for(int i=0;i<n;i++)
        cin>>arr1[i];
    for(int i=0;i<m;i++)
        cin>>arr2[i];

    merge(arr1,arr2,n,m);

    for(int i=0;i<n;i++)
        cout<<arr1[i]<<" ";
    for(int i=0;i<m;i++)
        cout<<arr2[i]<<" ";
    

    return 0;
}

// function to merge two sorted arrays without using extra space using gap method

void swap(int *n,int *m){
    int temp=*n;
    *n=*m;
    *m=temp;
}

int nextGap(int gap){
    if(gap<=1)
        return 0;
    return((gap/2) + (gap%2));
}

void merge(int first[],int second[],int n,int m){

    int gap=nextGap(n+m);
    while(gap){
        
        int i,j;

        for(i=0;i+gap<n;i++)
            if(first[i]>first[i+gap])
                swap(first[i],first[i+gap]);
        
        for(j=gap>n?gap-n:0;i<n && j<m;i++,j++)
            if(first[i]>second[j])
                swap(first[i],second[j]);

        if(j<m){
            for(j=0;j+gap<m;j++)
                if(second[j]>second[j+gap])
                    swap(second[j],second[j+gap]);
        }

        gap=nextGap(gap);
    }
}