#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<map>
using namespace std;


struct Node{
    int data;
    Node *next;
    Node(int dt){
        data=dt;
        next=NULL;
    }
};

Node* removeDuplicates(Node*);

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
    head=removeDuplicates(head);
    printList(head);

    return 0;
}


// Function to remove duplicates from an Un-sorted LinkedList

Node* removeDuplicates(Node *head){

    if(!head || !head->next)
        return NULL;

    Node *curr=head,*prev=NULL;
    map<int,bool>mp;
    mp[curr->data]=1;
    while(curr->next){
        prev=curr;
        curr=curr->next;
        if(mp.find(curr->data) != mp.end()){
            Node *del=curr;
            curr=prev;
            prev->next=del->next;
            delete del;
        }else
            mp[curr->data]=1;
    }

    return head;
}