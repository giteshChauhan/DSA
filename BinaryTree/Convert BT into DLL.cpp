#include<iostream>
#include<vector>
#include<queue>
#include<sstream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int dt){
        data=dt;
        left=right=NULL;
    }

};

Node *bToDLL(Node*);

Node * buildTree(string str){
    if(str.length()==0 || str[0]=='N')
        return NULL;
    
    vector<string> ip;
    istringstream strm(str);
    for(string str;strm>>str;)
        ip.push_back(str);
    
    Node *root=new Node(stoi(ip[0]));
    queue<Node*>q;
    q.push(root);
    int i=1;
    while(!q.empty() && i<ip.size()){
        Node *temp=q.front();
        q.pop();
        if(ip[i]!="N"){
            temp->left=new Node(stoi(ip[i]));
            q.push(temp->left);
        }
        i++;
        if(i>=ip.size())
            break;
        if(ip[i]!="N"){
            temp->right=new Node(stoi(ip[i]));
            q.push(temp->right);
        }
        i++;
    }

    return root;
    
}

void printList(Node *head){
    while(head){
        cout<<head->data<<" ";
        head=head->right;
    }
}

int main(){
    string str;
    getline(cin,str);
    Node *root=buildTree(str);
    Node*head=bToDLL(root);
    printList(head);
    return 0;
}

// Function to convert binary tree into doubly linked list.

/*
    Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and right pointers
    in nodes are to be used as previous and next pointers respectively in converted DLL. The order of nodes
    in DLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (leftmost
     node in BT) must be the head node of the DLL.
*/

void traverse(Node*root,Node* &head,Node* &prev,int &f){

    if(!root)
        return;

    traverse(root->left,head,prev,f);

    if(f == 0){
        head=prev=root;
        f=1;
    }else{
        prev->right=root;
        prev->right->left=prev;
        prev=prev->right;
    }

    traverse(root->right,head,prev,f);   
}

Node*bToDLL(Node *root){

    Node*head=NULL,*prev=NULL;
    int f=0;
    traverse(root,head,prev,f);
    return head;
}