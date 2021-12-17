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

int getMiddle(Node *);

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

int main(){
    string s;
    getline(cin,s);
    Node *head=buildList(s);
    int mid=getMiddle(head);
    cout<<mid;   

    return 0;
}


// Function to find the middle element in a linked list
/*
    Given a singly linked list of N nodes.
    The task is to find the middle of the linked list. For example, if the linked list is
    1-> 2->3->4->5, then the middle node of the list is 3.
    If there are two middle nodes(in case, when N is even), print the second middle element.
    For example, if the linked list given is 1->2->3->4->5->6, then the middle node of the list is 4
*/


int getMiddle(Node *head){
    if(!head)
        return -1;
    
    Node *fast=head,*slow=head;
    while(fast->next && fast->next->next){
        fast=fast->next->next;
        slow=slow->next;
    }

    int n=0;
    Node *temp=head;
    while(temp){
        temp=temp->next;
        n++;
    }

    if(n%2 ==0 )
        return(slow->next->data);
    else 
        return(slow->data);
}