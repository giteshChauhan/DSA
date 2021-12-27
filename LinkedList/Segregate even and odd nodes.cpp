#include<iostream>
#include<vector>
#include<sstream>
#include<string>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int dt){
        data=dt;
        next=NULL;
    }
};

Node *buildList(string s){
    if(s.length()==0)
        return NULL;
    
    vector<string>v;
    istringstream strm(s);
    for(string str;strm>>str;)
        v.push_back(str);
    
    Node *head=new Node(stoi(v[0]));
    Node *tail=head;
    for(int i=1;i<v.size();i++){
        tail->next=new Node(stoi(v[i]));
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

Node *divide(Node*);

int main(){

    string s;
    getline(cin,s);
    Node *head=buildList(s);
    head=divide(head);
    printList(head);

    return 0;
}


// Function to segregate even and odd nodes of linked list (such that even terms appears first and order is maintained )

Node *divide(Node *head){

    Node *evenH=new Node(-1),*evenT=evenH,*oddH=new Node(-1),*oddT=oddH;
    while(head){
        int val=head->data;
        if(val%2 == 0){
            evenT->next=head;
            evenT=head;
        }else{
            oddT->next=head;
            oddT=head;
        }
        head=head->next;
    }
    oddT->next=NULL;
    evenT->next=oddH->next;
    head=evenH->next;

    return head;
}