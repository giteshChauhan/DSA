#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int dt){
        data=dt;
        next=NULL;
    }
};


// Function to merge k sorted linked lists.


Node *merge(Node *first,Node *second){
        
    if(!first)
        return second;
    else if(!second)
        return first;
        
    Node *res=NULL;
        
    if(first->data < second->data){
        res=first;
        res->next=merge(first->next,second);
    }else{
        res=second;
        res->next=merge(first,second->next);
    }
        
    return res;
}
    
Node * mergeKLists(Node *arr[], int k){

    if(k==1)
        return arr[0];
        
    Node *res=merge(arr[0],arr[1]);    
    for(int i=2;i<k;i++)
        res=merge(res,arr[i]);
        
        return res;
}