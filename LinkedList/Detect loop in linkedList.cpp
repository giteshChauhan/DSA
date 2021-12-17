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

// Function to detect a loop in a linkedlist.

bool detectLoop(Node * head){
    if(!head)
        return 0;
    
    Node *slow=head,*fast=head;
    while(fast->next && fast->next->next){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast)
            return 1;
    }

    return 0;
}