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

Node* findIntersection(Node *,Node*);

int main(){

    string s1,s2;
    getline(cin,s1);
    Node *first=buildList(s1);
    getline(cin,s2);
    Node *second=buildList(s2);
    Node *inter=findIntersection(first,second);
    printList(inter);

    return 0;
}


// Function to find the intersection of two sorted linked lists.

Node *findIntersection(Node *head1,Node *head2){

    Node *res=NULL,*tail=NULL;
    
    while(head1 && head2){
        
        if(head1->data < head2->data)
            head1=head1->next;
        else if(head2->data < head1->data)
            head2=head2->next;
        else{
            if(!res){
                res=new Node(head1->data);
                tail=res;
            }else{
                tail->next=new Node(head1->data);
                tail=tail->next;
            }
            head1=head1->next;
            head2=head2->next;
        }
    }
    
    return res;
}