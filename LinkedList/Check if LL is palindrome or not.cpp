#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int dt){
        data=dt;
        next=NULL;
    }
};

Node* buildList(string s){
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
        tail=tail->next;
    }

    return head;
}

bool isPalindrome(Node*);

int main(){

    string s;
    getline(cin,s);
    Node* head=buildList(s);
    bool res=isPalindrome(head);
    cout<<res;

    return 0;
}


// Function to check if Linked List is palindrome or not.

Node *reverse(Node *head){
    if(!head || !head->next)
        return head;
    
    Node *cnext=NULL,*prev=NULL;
    while(head){
        cnext=head->next;
        head->next=prev;
        prev=head;
        head=cnext;
    }
    return prev;
}

bool isPalindrome(Node *head){

    Node *p1=head,*p2=head;
    while(p1->next && p1->next->next){
        p1=p1->next->next;
        p2=p2->next;
    }

    p2->next=reverse(p2->next);

    p1=head;
    while(p2->next){
        p2=p2->next;
        if(p1->data != p2->data)
            return 0;
        p1=p1->next;
    }
    return 1;
}