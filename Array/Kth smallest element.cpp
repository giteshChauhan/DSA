#include<iostream>
#include<queue>
#include<map>
using namespace std;

// Function to find the Kth smallest element in an array. l:first index , r:last index , k: position

    // Method 0 - Using Any Sorting Algorithm or using Set : Time - O(n logn)

    // Method 1 - QuickSelect  : Time - O(n) worst Case - O(n^2)  Space - O(1)

        void swap(int arr[],int i,int j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }

        int partition(int arr[],int pivot,int l,int r){
            int i=l,j=l;
            while(i <= r){
                if(arr[i] <= pivot){
                    swap(arr,i,j);
                    i++;
                    j++;
                }
                else i++;
            }

            return(j-1);
        }

        int kthSmallest(int arr[],int l,int r,int k){
            int pivot=arr[r];
            int pi=partition(arr,pivot,l,r);

            if(k-1 > pi)
                return kthSmallest(arr,pi+1,r,k);
            else if(k-1 < pi)
                return kthSmallest(arr,l,pi-1,k);
            else return pivot;
        }



    // Method 2 (Expert level,Best Soln) - https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-3-worst-case-linear-time/



    // Method 3 - PriorityQueue (Implementation of Min/Max heap)  : Time - O(n + klog n)  Space - O(n)
        int kthSmallest1(int arr[],int l,int r,int k){
            priority_queue<int>q;
            for(int i=0;i<k;i++)
                q.push(arr[i]);

            for(int i=k;i< r-l+1;i++){
                if(q.top() > arr[i]){
                    q.pop();
                    q.push(arr[i]);
                }
            }

            return(q.top());
        }

    
    // Method 4 - Using Map (Simpler version of quickSelect or countSort)  : Time - O(n)  Space - O(n)

        int kthSmallest2(int arr[],int l,int r,int k){
            map<int,int> m;
            for (int i = 0; i < r-l+1; i++) 
                m[arr[i]] += 1;

            int freq = 0;
            for (auto it = m.begin(); it != m.end(); it++) {
                freq += (it->second);
                if (freq >= k)
                    return it->first;
            }

            return -1;
        }


int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int k;
    cin>>k;

    int kSmall=kthSmallest(arr,0,n-1,k);
    cout<<kSmall<<endl;

    return 0;
}