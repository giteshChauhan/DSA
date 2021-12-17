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

// Function to delete a loop from the linked list.

void removeLoop(Node *head){
    if(!head)
        return;

    Node *p1=head,*p2=head;
    while(p1->next && p1->next->next){
        p1=p1->next->next;
        p2=p2->next;
        if(p1 == p2)
            break;
    }

    int n=1;
    while(p2->next == p1){
        p2=p2->next;
        n++;
    }
    p1=head;

    p2=head;
    for(int i=0;i<n;i++)
        p2=p2->next;

    while(p1!=p2){
        p1=p1->next;
        p2=p2->next;
    }    

    while(p2->next != p1)
        p2=p2->next;

    p2->next=NULL;
}