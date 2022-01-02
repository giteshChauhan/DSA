#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node *prev;
    Node*next;
    Node(int dt){
        data=dt;
        prev=NULL;
        next=NULL;
    }
};

Node* sortKSortedDLL(Node*,int);

Node * buildList(string s){
    if(s.length()==0)
        return NULL;

    vector<string>ip;
    istringstream strm(s);
    for(string str;strm>>str;)
        ip.push_back(str);

    Node *head=new Node(stoi(ip[0]));
    Node *tail=head;
    for(int i=1;i<ip.size();i++){
        tail->next=new Node(stoi(ip[i]));
        tail->next->prev=tail;
        tail=tail->next;
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
    int k;
    cin>>k;
    head=sortKSortedDLL(head,k);
    printList(head);

    return 0;
}

//Given a doubly linked list containing n nodes, where each node is at most k away from its target position in the list.
// The problem is to sort the given doubly linked list.

// Function to sort a k sorted doubly linked list

struct compare{
    bool operator ()(Node *p1,Node *p2){
        return(p1->data > p2->data);
    }
};

Node *sortKSortedDLL(Node *head,int k){

    if(!head || !head->next)
        return head;

    priority_queue<Node*,vector<Node*>,compare>pq;
    Node *newHead=NULL,*last=NULL;

    for(int i=0;head && i<=k;i++){
        pq.push(head);
        head=head->next;
    }

    while(!pq.empty()){
        if(!newHead){
            newHead=pq.top();
            newHead->prev=NULL;
            last=newHead;
        }else{
            last->next=pq.top();
            pq.top()->prev=last;
            last=pq.top();
        }
        pq.pop();

        if(head){
            pq.push(head);
            head=head->next;
        }
    }
    last->next=NULL;

    return newHead;
}