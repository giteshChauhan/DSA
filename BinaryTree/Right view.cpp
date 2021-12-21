#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<string>
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
};

vector<int>rightView(Node*);

Node *buildTree(string s){
    if(s.length() == 0 || s[0]=='N')
        return NULL;

    vector<string>v;
    istringstream strm(s);
    for(string str;strm>>str;)
        v.push_back(str);

    Node *root=new Node(stoi(v[0]));
    queue<Node*>q;
    q.push(root);
    int i=1;
    while(!q.empty() && i < v.size()){
        Node *temp=q.front();
        q.pop();
        if(v[i] != "N"){
            temp->left=new Node(stoi(v[i]));
            q.push(temp->left);
        }
        i++;
        if(i >= v.size())
            break;
        if(v[i] != "N"){
            temp->right=new Node(stoi(v[i]));
            q.push(temp->right);
        }
        i++;
    }

    return root;
}

int main(){
    string s;
    getline(cin,s);
    Node *root=buildTree(s);
    vector<int>left=rightView(root);
    for(auto i:left) cout<<i<<" ";
    return 0;
}


// Function to find the right view of the given binary tree

void getRight(Node* root,int h,vector<int>&res){
    if(!root)
        return;
    
    if(h == res.size())
        res.push_back(root->data);

    getRight(root->right,h+1,res);
    getRight(root->left,h+1,res);
}

vector<int>rightView(Node *root){

    vector<int>res;
    getRight(root,0,res);
    return res;
}