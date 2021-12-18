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

Node* lastToFront(Node*);

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
    head=lastToFront(head);
    printList(head);

    return 0;
}

// Function to move the last element to the front of linked list.

Node* lastToFront(Node* head){

    if(!head || !head->next)
        return head;

    Node *curr=head,*prev=NULL;
    while(curr->next){
        prev=curr;
        curr=curr->next;
    }
    prev->next=NULL;
    curr->next=head;
    head=curr;

    return head;
}