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

Node* reverse(Node*,int);

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
    int k;
    cin>>k;
    head=reverse(head,k);
    printList(head);

    return 0;
}

// Function to reverse the list in the group of k elements

Node * reverse(Node *head,int k){

    if(!head)
        return head;

    Node *prev=NULL,*curr=head,*cnext=NULL,*temp=NULL;

    for(int i=0;i<k && curr;i++){
        cnext=curr->next;
        curr->next=prev;
        prev=curr;
        curr=cnext;
    }
    temp=reverse(curr,k);
    head->next=temp;

    return prev;
}