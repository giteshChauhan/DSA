#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<sstream>
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
    istringstream iss(str);
    for(string str;iss >> str;)
        ip.push_back(str);

    Node *root=new Node(stoi(ip[0]));

    queue<Node*>q;
    q.push(root);

    int i=1;
    while(!q.empty() && i<ip.size()){

        Node *currNode =q.front();
        q.pop();

        string currVal=ip[i];

        if(currVal != "N"){
            currNode->left=new Node(stoi(currVal));
            q.push(currNode->left);
        }

        i++;
        if(i>=ip.size())
            break;
        currVal=ip[i];

        if(currVal !="N"){
            currNode->right=new Node(stoi(currVal));
            q.push(currNode->right);
        }
        i++;

    }

    return root;

}

vector<int>levelOrderTraversal(Node*);

int main(){

    string s;
    getline(cin,s);
    Node *root=buildTree(s);
    vector<int>res =levelOrderTraversal(root);
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