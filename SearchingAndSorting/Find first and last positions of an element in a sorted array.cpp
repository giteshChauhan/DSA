#include<iostream>
#include<vector>
using namespace std;

// Function to find first and last positions of an element in a sorted array.

int binarySearch(int arr[],int i,int j,int x,char t){
    int res=-1;
    while(i<=j){
        int mid=i+(j-i)/2;
        if(arr[mid] == x){
            res=mid;
            if(t == 'f')
                j=mid-1;
            else
                i=mid+1;
                
        }else if(arr[mid] < x)
            i=mid+1;
              else
            j=mid-1;
    }
    
    return res;
}

vector<int> find(int arr[], int n , int x )
{
    vector<int>v(n,-1);
    v[0]=binarySearch(arr,0,n-1,x,'f');
    v[1]=binarySearch(arr,0,n-1,x,'l');
    
    return v;
}

/*
    Given a sorted array arr containing n elements with possibly duplicate elements, the task
    is to find indexes of first and last occurrences of an element x in the given array.
*/

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int x;
    cin>>x;
    vector<int>res=find(arr,n,x);
    cout<<res[0]<<" "<<res[1]<<endl;

    return 0;
}