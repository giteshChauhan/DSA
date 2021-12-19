#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Function to print elements in sorted order using row-column wise sorted matrix

vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        
        vector<int>v;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                v.push_back(Mat[i][j]);
                
        sort(v.begin(),v.end());
        
        int k=0;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                Mat[i][j]=v[k++];
                
        return Mat;
}

int main(){

    int N;
    cin>>N;
    vector<vector<int>>v(N,vector<int>(N));
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>v[i][j];

    v=sortedMatrix(N,v);
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }


    return 0;
}