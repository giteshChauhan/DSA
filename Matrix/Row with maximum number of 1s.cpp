#include<iostream>
#include<vector>
using namespace std;

// Function to find the row with maximum number of 1s. O(n+m)

/*
    Given a boolean 2D array of n x m dimensions where each row is SORTED. 
    Find the 0-based index of the first row that has the maximum number of 1's
*/

int rowWithMax1s(vector<vector<bool>>arr,int n,int m){

    int idx=-1,i=0,j=m-1;
    
    while(i<n && j>=0){
        if(arr[i][j] == 1){
            idx=i;
            j--;
        }else
            i++;
    }

    return idx;
}


/*
    Logic :

    * To solve in O(N + M) start from the top right corner of the matrix and 
      keep track of the index of the row which has maximum 1s. 
    * Go left if you encounter 1
    * Go down if you encounter 0
    * Stop when you reach the last row or first column. 

*/