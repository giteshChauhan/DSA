#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int dt){
        data=dt;
        next=NULL;
    }
};

void reverseList(Node**);

Node *buildList(string str){
    if(str.length()==0)
        return NULL;
    
    Node *head=NULL;
    vector<string> v;
    istringstream strm(str);
    for(string s;strm>>s;)
        v.push_back(s);
    
    Node *prevNode=NULL;
    for(int i=0;i<v.size();i++){
        if(!head){
            head=new Node(stoi(v[i]));
            prevNode=head;
        }
        else{
            prevNode->next=new Node(stoi(v[i]));
            prevNode=prevNode->next;
        }
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
    string s;
    getline(cin,s);
    Node *head=buildList(s);
    reverseList(&head);
    printList(head);

    return 0;
}


// Function to reverse the list iteratively

void reverseList(Node **head){
    Node* prev=NULL,*curr=*head;
    while(curr){
        curr=curr->next;
        (*head)->next=prev;
        prev=*head;
        *head=curr;
    }
    *head=prev;
}


// Function to reverse the list recursively

/*
    Node* reverseList(Node *head){
        if(!head || !head->next)
            return head;
        
        Node* rest=reverseList(head->next);
        head->next->next=head;

        head->next=NULL;

        return rest;
    }
*/