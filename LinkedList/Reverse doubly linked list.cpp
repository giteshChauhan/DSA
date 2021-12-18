#include<iostream>
#include<string>
#include<vector>
#include<sstream>
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

Node *reverseList(Node*);

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
    head=reverseList(head);
    printList(head);

    return 0;
}



// Function to reverse the doubly linked list

Node* reverseList(Node *head){

    if(!head || !head->next)
        return head;

    Node* prev=NULL,*currNext=head;
    while(currNext){
        currNext=currNext->next;
        head->next=prev;
        head->prev=currNext;
        prev=head;
        head=currNext;
    }
    head=prev;

    return head;
}
