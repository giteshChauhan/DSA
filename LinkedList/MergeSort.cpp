#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next=NULL;
    Node(int dt){
        data=dt;
        next=NULL;
    }
};

void mergeSort(Node**);

int main(){
    int n,v;
    cin>>n;
    Node *head=NULL,*tail=NULL;
    for(int i;i<n;i++){
        cin>>v;
        if(!head){
            head=new Node(v);
            tail=head;
        }else{
            tail->next=new Node(v);
            tail=tail->next;      
        }
    }

    mergeSort(&head);

    Node *temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    
    return 0;
}


// mergeSort function to sort the linked list

Node* merge(Node *first,Node *second){
    Node *result=NULL;
    if(!first)
        return(second);
    else if(!second)
        return(first);
    
    if(first->data < second->data){
        result=first;
        result->next=merge(first->next,second);
    }
    else{
        result=second;
        result->next=merge(first,second->next);
    }

    return result;
}

void partition(Node *headRef,Node **first,Node **second){
    Node *slow=headRef,*fast=headRef;

    while(fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    *first=headRef;
    *second=slow->next;
    slow->next=NULL;
}

void mergeSort(Node **head){
    Node *headRef=*head;
    if(!headRef || !headRef->next)
        return;
    
    Node *first=NULL,*second=NULL;
    partition(headRef,&first,&second);
    mergeSort(&first);
    mergeSort(&second);
    *head=merge(first,second);

}