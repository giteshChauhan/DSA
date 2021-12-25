#include<iostream>
using namespace std;

struct Node{
    int data;
    Node*next;
    Node(int dt){
        data=dt;
        next=NULL;
    }
};

// Function to split circular linked list into halves

void splitList(Node *head,Node **head1_ref,Node **head2_ref){

    if(!head->next)
        return;
    
    Node *slow=head,*fast=head;
    while(fast->next != head && fast->next->next!=head){
        fast=fast->next->next;
        slow=slow->next;
    }
    *head1_ref=head;
    if(fast->next != head)
        fast=fast->next;
    *head2_ref=slow->next;
    slow->next=*head1_ref;
    fast->next=*head2_ref;
}

