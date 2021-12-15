#include<iostream>
#include<vector>
using namespace std;

/*
    Given a matrix mat[][] of size N x M, where every row and column is sorted in increasing order, 
    and a number X is given. The task is to find whether element X is present in the matrix or not.
*/

// Function to search an element in a 2d matrix

bool matSearch(vector<vector<int> &mat,int N,int M,int X){

    int i=0,j=M-1;
    while(i<N && j>=0){

        if(mat[i][j] == X)
            return 1;
        else if(mat[i][j] > X)
            j--;
        else i++;

    }

    return 0;
}