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

int kthAncestor(Node *,int,int);

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
    int k,node;
    cin>>k>>node;
    cout<<kthAncestor(root,k,node);
    
    return 0;
}

// Function to find the kth ancestor of the given node in the binary tree

/*
    Given a binary tree of size  N, a node and a positive integer k., Your task is to complete the function kthAncestor(),
    the function should return the kth ancestor of the given node in the binary tree. If there does not exist any such
    ancestor then return -1.
*/

int traverse(Node *root,int k,int node,int &ans){
    if(!root || ans != -1)
        return -1;
    
    int l=traverse(root->left,k,node,ans);
    int r=traverse(root->right,k,node,ans);

    if(root->data == node)
        return 1;
    
    int val=max(l,r);
    if(val == k)
        ans=root->data;
    return val != -1 ? val+1 : -1;
}

int kthAncestor(Node *root,int k,int node){
    int ans=-1;
    traverse(root,k,node,ans);
    return ans;
}