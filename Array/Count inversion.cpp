#include<iostream>
using namespace std;

// Function to count inversions
/*
    Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. 
    If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then 
    the inversion count is the maximum. 
    Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
*/

void merge(long long arr[],long long mid,long long low,long long high,long long int &count){

    long long n1=mid -low +1,n2=high -mid;
    long long i1=0,i2=0,i=low,b[n1],c[n2];

    for(long long j=0;j<n1;j++)
        b[j]=arr[low+j];
    for(long long j=0;j<n2;j++)
        c[j]=arr[mid+1+j];

    while(n1 && n2){
        if(b[i1] > c[i2]){
            arr[i]=c[i2];
            i++;
            i2++;
            n2--;
            count+=n1;
        }else{
            arr[i]=b[i1];
            i1++;
            i++;
            n1--;
        }
    }

    while(n1){
        arr[i]=b[i1];
        i++;
        i1++;
        n1--;
    }

    while(n2){
        arr[i]=c[i2];
        i++;
        i2++;
        n2--;
    }
}

void mergeSort(long long arr[],long long low,long long high,long long int &count){
    if(low<high){
        long long mid=low+(high-low)/2;
        mergeSort(arr,low,mid,count);
        mergeSort(arr,mid+1,high,count);
        merge(arr,mid,low,high,count);
    }
}

long long int inversionCount(long long arr[],long long N){
    long long int count=0;
    mergeSort(arr,0,N-1,count);
    return count;
}

int main(){

    long long N;
    cin>>N;
    long long arr[N];
    for(long long i=0;i<N;i++)
        cin>>arr[i];
    long long count=inversionCount(arr,N);

    return 0;
}