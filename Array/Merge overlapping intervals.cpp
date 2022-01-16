#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Function to merge overlapping intervals

vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {

    vector<vector<int>>mergedIntervals;
    if(intervals.size() == 0)
        return mergedIntervals;
            
    sort(intervals.begin(),intervals.end());
        
    vector<int>pairInterval=intervals[0];
    for(auto it:intervals){
        if(it[0] <= pairInterval[1])
            pairInterval[1]=max(it[1],pairInterval[1]);
        else{
            mergedIntervals.push_back(pairInterval);
            pairInterval=it;
        }
    }
    mergedIntervals.push_back(pairInterval);
        
    return mergedIntervals;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>Intervals(n);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        Intervals[i].push_back(x);
        Intervals[i].push_back(y);
    }
    vector<vector<int>>res=overlappedInterval(Intervals);
    for(auto it:res)
        cout<<it[0]<<" "<<it[1]<<endl;
    return 0;
}