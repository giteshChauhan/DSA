#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<string>
#include<sstream>
#include<stack>
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

vector<int>boundary(Node*);

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
    vector<int>bdry=boundary(root);
    for(auto i:bdry) cout<<i<<" ";
    return 0;
}


// Function to find the boundary elements by traversing the binary tree


void addLeftBoundary(Node *root,vector<int>&res){

    Node *currNode=root;
    while(currNode){
        if(currNode->left || currNode->right) res.push_back(currNode->data);// not a leaf node.
        if(currNode->left) currNode=currNode->left;
        else currNode=currNode->right;
    }
}

void addRightBoundaryRev(Node *root,vector<int>&res){

    stack<int>st;
    Node *currNode=root->right;
    while(currNode){
        if(currNode->right || currNode->left) st.push(currNode->data);// not a leaf node
        if(currNode->right) currNode=currNode->right;
        else currNode=currNode->left;
    }
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
}

void leafNodes(Node *root,vector<int>&res){
    if(root){
        leafNodes(root->left,res);
        if(!root->left && !root->right) res.push_back(root->data); // leaf node
        leafNodes(root->right,res);
    }
}

vector<int>boundary(Node *root){

    vector<int>res;
    if(!root){
        res.push_back(-1);
        return res;
    }

    addLeftBoundary(root,res);
    leafNodes(root,res);
    addRightBoundaryRev(root,res);

    return res;
}

