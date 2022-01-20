#include<iostream>
using namespace std;

// Function to rearrange the elements of array such that every positive element is followed by negative number and vice-versa.
//  1) while maintaining the order of appearance.

void swap(int &i,int &j){
    int temp=i;
    i=j;
    j=temp;
}

void rotateRight(int arr[],int si,int ei){
    while(si<ei){
        swap(arr[ei],arr[si]);
        si++;
    }
}

void rearrange(int arr[],int n){

    int j;
    for(int i=0;i<n;i++){
        j=i;
        if(i%2 == 0 && arr[i] >=0){
            while(arr[j] >=0 && j<n)
                j++;
            if(j>=n) break;
            rotateRight(arr,i,j);
        }else if(i%2 !=0 && arr[i] < 0){
            while(arr[j] <0 && j<n)
                j++;
            if(j>=n) break;
            rotateRight(arr,i,j);
        }
    }
}

// 2) Not maintaining the order of appearance.

void rearrange2(int arr[], int n){

    int i = 0, j = n-1;
    while (i < j) {
        while (i <= n - 1 and arr[i] > 0)
            i += 1;
        while (j >= 0 and arr[j] < 0)
            j -= 1;
        if (i < j )
            swap(arr[i], arr[j]);
    }
 
    if (i == 0 || i == n)
        return;

    int k = 0;
    while (k < n && i < n ) {
        swap(arr[k], arr[i]);
        i = i + 1;
        k = k + 2;
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    rearrange(arr,n);
    for(auto i:arr)
        cout<<i<<" ";
    return 0;
}

