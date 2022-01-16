#include<iostream>
using namespace std;

// Function to find the duplicate in an array of n+1 intergers
/*
    Given an array of integers containing n + 1 integers where each integer is in the range [1, n] inclusive.
    There is only one repeated number in array, return this repeated number.

   Note : You must solve the problem without modifying the array and uses only constant extra space.
          All the integers in array appear only once except for precisely one integer which appears two or more times.
*/

int findDuplicate(int arr[],int n){

    int fast=arr[0],slow=arr[0];
    do{
        slow=arr[slow];
        fast=arr[arr[fast]];
    }while(slow != fast);

    fast=arr[0];
    while(slow != fast){
        slow=arr[slow];
        fast=arr[fast];
    }

    return slow;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<findDuplicate(arr,n);
    return 0;
}