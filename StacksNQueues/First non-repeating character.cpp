#include<iostream>
#include<queue>
using namespace std;

// Function to find the first non-repeating character from the stream of characters.
// Here queue approach is used rather we can also use Doubly linked list approach (as shown in linked list repo).

/*
    Given an input stream of A of n characters consisting only of lower case alphabets.
    The task is to find the first non repeating character, each time a character is inserted to the stream.
    If there is no such character then append '#' to the answer.
*/

string firstNonRepeating(string a){

    int arr[26]={0};
    queue<int>q;
    for(int i=0;i<a.length();i++){
        arr[a[i]-'a']++;
        if(arr[a[i]-'a'] == 1)
            q.push(a[i]);
        
        while(!q.empty() && arr[q.front()-'a'] != 1)
            q.pop();
        
        if(q.empty())
            a[i]='#';
        else
            a[i]=q.front();
    }

    return a;
}