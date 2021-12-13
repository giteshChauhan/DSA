#include<iostream>
using namespace std;

/*
struct Node{
    int data;
    Node *left;
    Node*right;
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

*/

// Function to mirror a tree

void mirrorTree(Node *root){

    if(!root || (!root->left && !root->right))
        return;
    Node *temp=root->left;
    root->left=root->right;
    root->right=temp;
    mirrorTree(root->left);
    mirrorTree(root->right);

}