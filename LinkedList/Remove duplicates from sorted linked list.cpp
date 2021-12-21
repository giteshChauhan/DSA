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

Node* removeDuplicates(Node*);

Node *buildList(int arr[],int n){

    Node *head=new Node(arr[0]);
    Node *temp=head;
    for(int i=1;i<n;i++){
        temp->next=new Node(arr[i]);
        temp=temp->next;
    }

    return head;
}

void printList(Node *head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];        // input must be sorted list

    Node *head=buildList(arr,n);
    head=removeDuplicates(head);
    printList(head);

    return 0;
}


// Function to remove duplicates from the sorted linked list

Node *removeDuplicates(Node *head){
    
    Node *prev=head,*curr=head;
    while(curr->next){
        curr=curr->next;
        if(curr->data == prev->data){
            Node *del=curr;
            curr=prev;
            prev->next=del->next;
            delete del;
        }else
            prev=curr;
    }

    return head;
}