#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// Function to find the common elements in three sorted arrays.

vector<int>commonElements(int a[],int b[],int c[],int n1,int n2,int n3){

    vector<int>res;
    int i=0,j=0,k=0;
    int prev1=INT_MIN,prev2=INT_MIN,prev3=INT_MIN;

    while(i<n1 && j<n2 && k<n3){
        
        while(a[i] == prev1 && i<n1)
            i++;

        while(b[j] == prev2 && j<n2)
            j++;
        
        while(c[k] == prev3 && k<n3)
            k++;

        if(a[i] == b[j] && a[i] == c[k]){
            res.push_back(a[i]);
            prev1=prev2=prev3=a[i];
            i++;
            j++;
            k++;
        }else if(a[i] < b[j]){
            prev1=a[i];
            i++;
        }else if(b[j] < c[k]){
            prev2=b[j];
            j++;
        }else{
            prev3=c[k];
            k++;
        }
    }

    return res;
}

int main(){
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    int a[n1],b[n2],c[n3];
    for(int i=0;i<n1;i++)
        cin>>a[i];
    for(int i=0;i<n2;i++)
        cin>>b[i];
    for(int i=0;i<n3;i++)
        cin>>c[i];
    sort(a,a+n1);
    sort(b,b+n2);
    sort(c,c+n3);
    vector<int>res=commonElements(a,b,c,n1,n2,n3);
    for(auto i:res)
        cout<<i<<" ";
    return 0;
}