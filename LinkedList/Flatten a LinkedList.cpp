#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *bottom;
    Node(int dt){
        data=dt;
        next=NULL;
        bottom=NULL;
    }
};

Node *flatten(Node*);

int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    Node *head=NULL,*forth=NULL,*down=NULL;
    int data;
    for(int i=0;i<n;i++){
        cin>>data;
        if(!head){
            head=new Node(data);
            forth=head;
            down=head;
        }else{
            forth->next=new Node(data);
            down=forth;
            forth=forth->next;
        }
        for(int j=0;j<arr[i]-1;j++){
            cin>>data;
            down->bottom=new Node(data);
            down=down->bottom;
        }
    }

    Node *root=NULL;
    root=flatten(head);

    Node *temp=root;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->bottom;
    }

    return 0;
}


// Flatten function to flat the LinkedList

Node *merge(Node *first,Node *second){

    if(!first)
        return second;
    else if(!second)
        return(first);
    
    Node *res=NULL;
    if(first->data<second->data){
        res=first;
        res->bottom=merge(first->bottom,second);
    }else{
        res=second;
        res->bottom=merge(first,second->bottom);
    }

    return res;
}

Node *flatten(Node *root){
    if(!root || !root->next)
        return root;

    return(merge(root,flatten(root->next)));
}