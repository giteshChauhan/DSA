#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node* left,*right;
    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};


Node *leavesToDLL(Node *&);


Node *buildTree(string s){
    if(s.length() == 0 || s[0] == 'N')
        return NULL;

    vector<string>v;
    istringstream strm(s);
    for(string str;strm>>str;)
        v.push_back(str);

    Node *root=new Node(stoi(v[0]));
    queue<Node*>q;
    q.push(root);
    for(int i=1;i<v.size();i++){
        Node *curr=q.front();
        q.pop();
        if(v[i] != "N"){
            curr->left=new Node(stoi(v[i]));
            q.push(curr->left);
        }
        i++;
        if(i >= v.size())
            break;

        if(v[i] != "N"){
            curr->right=new Node(stoi(v[i]));
            q.push(curr->right);
        }
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
    string s;
    getline(cin,s);
    Node *root=buildTree(s);
    Node *head=leavesToDLL(root);
    printList(head);
    return 0;
}

// Function to create doubly linked list with leaves of the binary tree ( from left to right ).
// Note : left is considered as previous and right is considered as next node of DLL

Node *traverse(Node *root,Node* &head,Node* &prev){
    if(!root)
        return root;

    if(!root->left && !root->right){
        if(!head)
            head=prev=root;
        else{
            prev->right=root;
            root->left=prev;
            prev=root;
        }
        return NULL;
    }

    root->left=traverse(root->left,head,prev);
    root->right=traverse(root->right,head,prev);

    return root;
}

Node *leavesToDLL(Node* &root){
    Node *head=NULL,*prev=NULL;
    root=traverse(root,head,prev);
    return head;
}