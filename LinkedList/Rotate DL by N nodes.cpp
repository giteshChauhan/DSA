#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

struct Node{
    int data;
    Node *next,*prev;
    Node(int dt){
        data=dt;
        next=NULL;
        prev=NULL;
    }
};

Node *buildList(string s){
    if(s.length() == 0)
        return NULL;
    
    vector<string>v;
    istringstream strm(s);
    for(string str;strm>>str;)
        v.push_back(str);
    
    Node *head=new Node(stoi(v[0]));
    Node *tail=head;
    for(int i=1;i<v.size();i++){
        tail->next=new Node(stoi(v[i]));
        tail->next->prev=tail;
        tail=tail->next;
    }
    return head;
}

Node *update(Node*,int);

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
    int N;
    cin>>N;
    head=update(head,N);
    printList(head);

    return 0;
}

// Function to rotate the doubly linked list by N nodes (here N is smaller than number of nodes)

Node *update(Node *head,int p){

    if(!head || !head->next)
        return head;
    
    Node *newHead=NULL,*newTail=head;
    while(--p)
        newTail=newTail->next;
    newHead=newTail->next;

    Node *tail=head;
    while(tail->next)
        tail=tail->next;
    
    newTail->next=NULL;
    newHead->prev=NULL;
    tail->next=head;
    head->prev=tail;

    return newHead;
}