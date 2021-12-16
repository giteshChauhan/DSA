#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

// Function to find largest rectangular area in histogram 

class Solution{
public:

    int largestRectangleArea(vector<int>&heights){
        int n=heights.size();
        stack<int>st;
        int leftSmall[n],rightSmall[n];

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            
            if(st.empty())
                leftSmall[i]=0;
            else
                leftSmall[i]=st.top() +1;
            
            st.push(i);
        }

        while(!st.empty()) st.pop();
    
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            
            if(st.empty())
                rightSmall[i]=n-1;
            else
                rightSmall[i]=st.top() - 1;
            
            st.push(i);
        }

        int maxArea =0;
        for(int i=0;i<n;i++)
            maxArea=max(maxArea,heights[i] * (rightSmall[i]-leftSmall[i]+1));
        
        return maxArea;

    }

};

int main(){
    int n;
    cin>>n;
    vector<int>heights;
    for(int i=0;i<n;i++){
        int j;
        cin>>j;
        heights.push_back(j);
    }
    Solution obj;
    int maxArea=obj.largestRectangleArea(heights);
    cout<<maxArea;


    return 0;
}


// Most optimal solution to complete the function in 1 pass

/*
    int largestRectangleArea(vector<int>&heights){
        stack<int>st;
        int maxA=0;
        int n=heights.size();
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || heights[st.top()] >= heights[i])){
                int height = heights[st.top()];
                st.pop();
                int width;
                if(st.empty())
                    width=i;
                else
                    width=i-st.top()-1;
                maxA=max(maxA,width*height);
            }
            st.push(i);
        }

        return maxA;
    }
*/