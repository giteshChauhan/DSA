#include<iostream>
#include<cmath>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int dt){
        data=dt;
        next=NULL;
    }
};

// Function to find the value of intersection point of two Y-shaped linked list

int size(Node *head){
    int n=0;
    while(head){
        head=head->next;
        n++;
    }
    return n;
}

int intersectionPoint(Node *head1,Node *head2){

    int n1=size(head1);
    int n2=size(head2);

    int delta=abs(n1-n2);
    Node *p1=head1,*p2=head2;

    for(int i=0;i<delta;i++){
        if(n1>n2)
            p1=p1->next;
        else
            p2=p2->next;
    }

    while(p1->next){
        p1=p1->next;
        p2=p2->next;
        if(p1 == p2)
            return p1->data;
    }
    return -1; // if there is no common point
}
