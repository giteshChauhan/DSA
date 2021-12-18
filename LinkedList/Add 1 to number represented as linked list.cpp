#include<iostream>
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

Node* addOne(Node *);

Node *buildList(string str){
    if(str.length()==0)
        return NULL;

    Node *head=new Node(str[0]-'0');
    Node *tail=head;
    for(int i=1;i<str.length();i++){
        tail->next=new Node(str[i]-'0');
        tail=tail->next;
    }

    return head;
}

void printNumber(Node *head){
    while(head){
        cout<<head->data;
        head=head->next;
    }
}

int main(){
    string s;
    cin>>s;
    Node *head=buildList(s);
    head=addOne(head);
    printNumber(head);

    return 0;
}

// Function to add 1 to a number represented as linked list.

Node * addOne(Node *head){

    if(!head)
        return head;
    if(!head->next){
        head->data+=1;
        return head;
    }

    Node *sum=addOne(head->next);
    head->data+=(sum->data/10);
    sum->data%=10;

    return head;
}