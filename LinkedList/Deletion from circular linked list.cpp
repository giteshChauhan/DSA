#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node *next=NULL;
    Node(int dt){
        data=dt;
        next=NULL;
    }
};

void deleteNode(Node**,int);

Node *buildList(string s){
    if(s.length()==0)
        return NULL;

    vector<string>ip;
    istringstream strm(s);
    for(string str;strm>>str;)
        ip.push_back(str);

    Node *head=new Node(stoi(ip[0]));
    head->next=head;
    Node *tail=NULL;
    for(int i=1;i<ip.size();i++){
        tail=new Node(stoi(ip[i]));
        tail->next=head->next;
        head->next=tail;
        head=tail;
    }

    return head;
}

void printList(Node *head){
    if(!head)
        return;

    Node *it=head->next;
    do{
        cout<<it->data<<" ";
        it=it->next;
    }while (it != head->next);
}

int main(){
    string s;
    getline(cin,s);
    Node *head=buildList(s);
    int k;
    cin>>k;
    deleteNode(&head,k);
    printList(head);

    return 0;
}




// Function to delete a node in the circular linked list.



Node *searchNode(Node *head,int k){
    Node *temp=head->next;
    do{
        if(temp->data == k)
            return temp;
        temp=temp->next;
    }while(temp != head->next);

    return NULL;
}

void deleteNode(Node **head,int k){

    if(!(*head))
        return;

    Node *delNode=searchNode(*head,k);

    if(!delNode)
        return;
    else if((*head)->next == (*head))
        *head=NULL;
    else if(delNode->data == (*head)->data){

        Node *temp=(*head)->next;
        while(temp->next != *head)
            temp=temp->next;
        (*head)=temp;
        (*head)->next=delNode->next;

    }else if(delNode->data == (*head)->next->data){

        (*head)->next=delNode->next;

    }else{

        Node *temp=(*head)->next;
        while(temp->next != delNode)
            temp=temp->next;
        temp->next=delNode->next;

    }

    delete delNode;
}
