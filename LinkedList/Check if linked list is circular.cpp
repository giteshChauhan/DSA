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

// Function to check whether a given linked list is circular or not.

bool isCircular(Node *head){

    if(!head)
        return 1;// empty list is considered as circular

    Node *it=head;
    while(it->next){
        it=it->next;
        if(it == head)
            return 1;
    }

    return 0;
}