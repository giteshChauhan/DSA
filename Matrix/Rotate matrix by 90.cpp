#include<iostream>
#include<vector>
using namespace std;

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

// Function to rotate matrix anticlockwise by 90 degrees

void rotateByNinety(vector<vector<int>> &mat,int n){

    for(int i=0;i<n;i++)
        for(int j=0;j<i;j++)
            swap(mat[i][j],mat[j][i]);

    for(int i=0;i<n;i++){
        int r1=0,r2=n-1;
        while(r1<r2){
            swap(mat[r1][i],mat[r2][i]);
            r1++;
            r2--;
        }
    }

}

int main(){

    int n;
    cin>>n;
    vector<vector<int>>mat(n);
    for(int i=0;i<n;i++){
        mat[i].assign(n,0);
        for(int j=0;j<n;j++)
            cin>>mat[i][j];
    }

    rotateByNinety(mat,n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}