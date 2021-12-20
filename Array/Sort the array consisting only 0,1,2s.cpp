#include<iostream>
#include<algorithm>
using namespace std;

// Function to sort the array consistin only 0s 1s and 2s without using any sorting algo.  Time - O(n)

    // count Sort method

    void sort012(int a[],int n){

        int count[3]={0};
        for(int i=0;i<n;i++){
            if(a[i] == 0)
                count[0]++;
            else if(a[i] == 1)
                count[1]++;
            else count[2]++;
        }

        for(int i=0;i<n;i++){
            if(count[0]){
                a[i]=0;
                count[0]--;
            }else if(count[1]){
                a[i]=1;
                count[1]--;
            }else{
                a[i]=2;
                count[2]--;
            }
        }
    }


    // Dutch Flag Algorithm

    void sort012_(int a[],int n){

        int low=0, mid=0, high=n-1;
       
       while(mid<=high){
           if(a[mid]==0)
                swap(a[low++], a[mid++]);
           else if(a[mid]==1)
               mid++;
           else if(a[mid]==2)
               swap(a[mid], a[high--]);
       }
    }

int main(){

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    sort012(a,n);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    return 0;
}