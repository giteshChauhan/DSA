#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next,*arb;
    Node(int dt){
        data=dt;
        next=NULL;
        arb=NULL;
    }
};

// Function to clone a given linked list contaiting next and random pointer.

/*
    Construct a copy of the given list. The copy should consist of exactly N new nodes, 
    where each new node has its value set to the value of its corresponding original node. 
    Both the next and random pointer of the new nodes should point to new nodes in the copied 
    list such that the pointers in the original list and copied list represent the same list state. 
    None of the pointers in the new list should point to nodes in the original list.

NOTE : 
1. If there is any node whose arbitrary pointer is not given then it's by default NULL. 
2. Your solution return an output 1 if your clone linked list is correct, else it returns 0.

*/


/*
    Algorithm Used: time-O(n) space-O(1)

   * Create the copy of node 1 and insert it between node 1 & node 2 in original Linked List, create the copy of 2 and insert it between 2 & 3..
     Continue in this fashion, add the copy of N afte the Nth node.

   * Now copy the random link in this fashion
     original->next->random= original->random->next;  // TRAVERSE TWO NODES
    This works because original->next is nothing but copy of original and Original->random->next is nothing but copy of random.

   * Now restore the original and copy linked lists in this fashion in a single loop.
     original->next = original->next->next;
     copy->next = copy->next->next;

   * Ensure that original->next is NULL and return the cloned list
*/

Node *copyList(Node *head){

    Node *curr=head,*cnext=NULL;
    while(curr){
        cnext=curr->next;
        curr->next=new Node(curr->data);
        curr->next->next=cnext;
        curr=cnext;
    }
        
    curr=head;
    while(curr){
        if(!curr->arb)
            curr->next->arb=NULL;
        else
            curr->next->arb=curr->arb->next;
        curr=curr->next->next;
    }
        
    Node *res=head->next;curr=head;cnext=res;
    while(cnext->next){
        curr->next=curr->next->next;
        cnext->next=cnext->next->next;
        curr=curr->next;
        cnext=cnext->next;
    }
    curr->next=NULL;
        
    return res;
}