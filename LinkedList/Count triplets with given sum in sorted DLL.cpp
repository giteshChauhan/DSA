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

int countTriplets(Node*,int);

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


Node *merge(Node *first,Node *second){
    if(!first)
        return second;
    else if(!second)
        return first;


    if(first->data < second->data){
        first->next=merge(first->next,second);
        first->next->prev=first;
        first->prev=NULL;
        return first;
    }else{
        second->next=merge(first,second->next);
        second->next->prev=second;
        second->prev=NULL;
        return second;
    }
}

void midNode(Node *head,Node *&first,Node *&second){
    Node *f=head,*s=head;
    while(f->next && f->next->next){
        f=f->next->next;
        s=s->next;
    }
    first=head;
    second=head->next;
    head->next=NULL;
}

Node *sortList(Node *head){
    
    if(!head || !head->next)
        return head;
    
    Node*first=NULL,*second=NULL;
    midNode(head,first,second);
    first=sortList(first);
    second=sortList(second);
    head=merge(first,second);
    return head;
}

int main(){
    string s;
    getline(cin,s);
    Node *head=buildList(s);
    int n;
    cin>>n;
    head=sortList(head);
    int count=countTriplets(head,n);
    cout<<count;

    return 0;
}


// Given a sorted doubly linked list of positive distinct elements, the task is to count number of triplets in a doubly-linked list
//   whose sum is equal to given value x, without using any extra space.

// Function to count the triplets with given sum.

int countTriplets(Node *head,int s){

    if(!head || !head->next || !head->next->next)
        return -1;

    int count=0;
    Node *f=head,*l=NULL,*m=head->next;
    while(m->next){
        l=head;
        while(l->next)
            l=l->next;
        
        int k=s - f->data;
        while(m->data < l->data){
            int parSum=m->data + l->data;
            if(parSum >k)
                l=l->prev;
            else if(parSum < k)
                m=m->next;
            else{
                count++;
                m=m->next;
                l=l->prev;
            }
        }
        f=f->next;
        m=f->next;
    }

    return count;
}