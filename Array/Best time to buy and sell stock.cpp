#include<iostream>
#include<vector>
using namespace std;

// Function to determine the best time to buy and sell stock
/*
    The cost of stock on each day is given in an array A[] of size N. Find all the days on which you buy and sell
    the stock so that in between those days your profit is maximum.
*/

vector<vector<int>> stockBuySell(vector<int>a,int n){

    vector<vector<int>>res;
    for(int i=1;i<n;i++){
        vector<int>v;
        if(a[i] > a[i-1]){
            v.push_back(i-1);
            while(i<n){
                if(a[i] >= a[i-1])
                    i++;
                else
                    break;
            }
            v.push_back(i-1);
            res.push_back(v);
        }
    }

    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int>a;
    for(int i=0;i<n;i++){
        int j;
        cin>>j;
        a.push_back(j);
    }
    vector<vector<int>>v=stockBuySell(a,n);
    for(auto i:v){
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}