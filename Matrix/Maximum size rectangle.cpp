#include<iostream>
#include<algorithm>
#include<stack>
#define MAX 1000
using namespace std;

// Function to find the maximum area of rectangle formed by 1s in the matrix of 0s and 1s.

int maxArea(int mat[MAX][MAX],int n,int m){

    int maxArea=0;
    int currRow[m]={0},leftSmall[m],rightSmall[m];
    stack<int>st;
    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){
            if(mat[i][j]==0)
                currRow[j]=0;
            else
                currRow[j]=1+currRow[j];
        }

        while(!st.empty()) st.pop();

        for(int k=0;k<m;k++){
            while(!st.empty() && currRow[st.top()] >= currRow[k])
                st.pop();
            if(st.empty())
                leftSmall[k]=0;
            else
                leftSmall[k]=st.top()+1;
            st.push(k);
        }

        while(!st.empty()) st.pop();
    
        for(int k=m-1;k>=0;k--){
            while(!st.empty() && currRow[st.top()] >= currRow[k])
                st.pop();
            if(st.empty())
                rightSmall[k]=m-1;
            else 
                rightSmall[k]=st.top() - 1;
            st.push(k);
        }

        for(int k=0;k<m;k++)
            maxArea=max(maxArea,currRow[k]*(rightSmall[k]-leftSmall[k]+1));

    }

    return maxArea;
}

int main(){
    int n,m;
    cin>>n>>m;
    int mat[MAX][MAX];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>mat[i][j];
    
    int  maxA=maxArea(mat,n,m);
    cout<<maxA;

    return 0;
}