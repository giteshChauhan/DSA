#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<queue>
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

Node *buildTree(string str){
    if(str.length()==0 || str[0]=='N')
        return NULL;
    
    vector<string> v;
    istringstream strm(str);
    for(string s;strm>>s;)
        v.push_back(s);
    
    Node *root=new Node(stoi(v[0]));
    queue<Node*>q;
    q.push(root);
    int i=1;
    while(!q.empty() && i<v.size()){
        Node *temp=q.front();
        q.pop();
        if(v[i]!="N"){
            temp->left=new Node(stoi(v[i]));
            q.push(temp->left);
        }
        i++;
        if(i>=v.size())
            break;
        if(v[i]!="N"){
           temp->right=new Node(stoi(v[i]));
           q.push(temp->right);
        }
        i++;
    }
    return root;
}

vector<int> reverseLevelOrderTraversal(Node*);

int main(){

    string s;
    getline(cin,s);
    Node *root=buildTree(s);
    vector<int> res=reverseLevelOrderTraversal(root);
    for(auto i: res) cout<<i<<" ";

    return 0;
}

// Function for reverse level order traversal

vector<int>reverseLevelOrderTraversal(Node *root){
    vector<int>v;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node *temp=q.front();
        q.pop();
        v.insert(v.begin(),temp->data);
        if(temp->right)
            q.push(temp->right);
        if(temp->left)
            q.push(temp->left);
    }

    return v;
}