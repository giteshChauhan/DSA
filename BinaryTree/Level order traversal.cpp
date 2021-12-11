#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node*right;
    Node(int dt){
        data=dt;
        left=NULL;
        right=NULL;
    }
};

Node *buildTree(string str){

    if(str.length()==0 || str[0] =='N')
        return NULL;
    
    vector<string> ip;
    isstringstream iss(str);

}

vector<int>levelOrderTraversal(Node*);

int main(){

    string s;
    getline(cin,s);
    Node *root=buildTree(s);
    vector<int>res=levelOrderTraversal(root);
    for(int i: res) cout<<i<<" ";

    return 0;
}

// function to traverse the binary tree in level order

vector<int>levelOrderTraversal(Node *node){

    vector<int>v;
    queue<Node*>q;
    q.push(node);
    while(!q.empty()){
        Node *temp=q.front();
        q.pop();
        v.push_back(temp->data);
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    return v;
}