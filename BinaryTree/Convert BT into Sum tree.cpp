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

void toSumTree(Node*);

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

void printTree(Node *root){
    if(root){
        printTree(root->left);
        cout<<root->data<<" ";
        printTree(root->right);
    }
}

int main(){
    string str;
    getline(cin,str);
    Node *root=buildTree(str);
    toSumTree(root);
    printTree(root);
    return 0;
}


// Function to convert the binary tree into sum tree

/*
    Given a Binary Tree of size N , where each node can have positive or negative values. Convert this to a tree
    where each node contains the sum of the left and right sub trees of the original tree. The values of leaf
    nodes are changed to 0.
*/


int traverse(Node *root){
    if(!root)
        return 0;

    int data=root->data;

    int l=traverse(root->left);
    int r=traverse(root->right);

    root->data=l+r;

    return data+root->data;
}

void toSumTree(Node *root){
    traverse(root);
}