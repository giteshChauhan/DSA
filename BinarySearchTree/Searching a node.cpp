#include<iostream>
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
};
bool searchNode(Node*,int);
Node *insert(Node *tree,int val){
    if(tree==NULL)
        return(new Node(val));
    if(val < tree->data)
        tree->left=insert(tree->left,val);
    else if(val > tree->data)
        tree->right=insert(tree->right,val);
    
    return tree;
}

int main(){
    int n;
    cin>>n;
    Node *root=NULL;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        root=insert(root,k);
    }
    cin>>n;
    bool res=searchNode(root,n);
    if(res)
        cout<<n<<" exists in a tree.";
    else
        cout<<n<<" does not exist in a tree.";

    return 0;
}


// Function to search a node in binary search tree

bool searchNode(Node *root,int val){
    if(!root)
        return 0;
    
    if(root->data == val)
        return 1;
    else if(val < root->data)
        return(searchNode(root->left,val));
    else
        return(searchNode(root->right,val));
}