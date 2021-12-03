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

void quickSort(Node**);

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

    quickSort(&head);

    Node *temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    
    return 0;
}

    
// QuickSort on singly linked list

Node* getTail(Node *headRef){
    if(!headRef)
        return NULL;
    
    while(headRef->next)
        headRef=headRef->next;

    return(headRef);    
}

Node *listPartition(Node *head,Node *tail,Node **newHead,Node **newTail){
    Node *pivot=tail,*prev=NULL,*curr=head,*last=pivot;

    while(curr != pivot){
        if(curr-> data < pivot->data){
            if((*newHead) == NULL)
                (*newHead)=curr;
            prev=curr;
            curr=curr->next;
        }else{
            if(prev)
                prev->next=curr->next;
            Node *temp=curr->next;
            curr->next=NULL;
            last->next=curr;
            last=curr;
            curr=temp;
        }
    }

    if((*newHead)==NULL)
        (*newHead)=pivot;
    (*newTail)=last;

    return(pivot);
}

Node* quick(Node *head,Node *tail){
    if(!head || head==tail)
        return head;
    
    Node *newHead=NULL,*newTail=NULL;
    Node *pivot=listPartition(head,tail,&newHead,&newTail);
    
    if(newHead != pivot){
        Node *temp=newHead;

        while(temp->next != pivot)
            temp=temp->next;
        temp->next=NULL;

        newHead=quick(newHead,temp);

        temp=getTail(newHead);
        temp->next=pivot;

    }
    pivot->next=quick(pivot->next,newTail);

    return(newHead);
}

void quickSort(Node **head){
    Node *headRef=*head,*tail=getTail(headRef);
    *head=quick(headRef,tail);
}