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
        left=NULL;
        right=NULL;
    }
    Node(){
        left=NULL;
        right=NULL;
    }
};

Node* lca(Node*,int,int);

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

int main(){
    string str;
    getline(cin,str);
    Node *root=buildTree(str);
    int n1,n2;
    cin>>n1>>n2;
    Node *c=lca(root,n1,n2);
    cout<<c->data;
    
    return 0;
}


// Function to find the least common ancestor of two nodes in a binary tree.

/*
    Given a Binary Tree with all unique values and two nodes valuen1 and n2. The task is to find the lowestcommon
    ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of
    them is present.
*/

Node *lca(Node *root,int n1,int n2){
    
    if(!root)
        return root;
    
    if(root->data == n1 || root->data == n2)
        return root;

    Node *l=lca(root->left,n1,n2);
    Node *r=lca(root->right,n1,n2);

    if(l && r)
        return root;
    else if(l)
        return l;
    else return r;
}