#include<iostream>
#include<vector>
using namespace std;

/*
    XOR LL:
        An ordinary Doubly Linked List requires space for two address fields to store the addresses of previous and next nodes.
        A memory efficient version of Doubly Linked List can be created using only one space for address field with every node. 
        This memory efficient Doubly Linked List is called XOR Linked List or Memory Efficient as the list uses bit-wise XOR operation
        to save space for one address.
*/

struct Node{
    int data;
    Node* npx; // XOR of next and prev
    Node(int dt){
        data=dt;
        npx=NULL;
    }
};

Node *insert(Node*,int);
vector<int>printList(Node*);

int main(){

    int n,val;
    cin>>n;
    Node *head=NULL;
    while(n--){
        cin>>val;
        head=insert(head,val);
    }
    vector<int>res=printList(head);
    for(auto i:res) cout<<i<<" ";
    cout<<endl;
    for(int i=res.size()-1;i>=0;i--)
        cout<<res[i]<<" ";

    return 0;
}

// Function to insert and print the values of list

Node * XOR(Node *a,Node*b){
    return((Node*)( (uintptr_t)(a) ^ (uintptr_t)(b) ));
}


Node *insert(Node *head,int data){  // inserts value in the beg

    Node *newNode=new Node(data);
    newNode->npx=XOR(head,NULL);
    if(head){
        Node *next=XOR(head->npx,NULL);
        head->npx=XOR(newNode,next);
    }
    head=newNode;
}

vector<int>printList(Node *head){

    vector<int>v;
    Node *next=NULL,*prev=NULL;
    while(head){
        v.push_back(head->data);
        next=XOR(prev,head->npx);
        prev=head;
        head=next;
    }
    return v;
}