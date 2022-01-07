#include<iostream>
#include<vector>
#include<queue>
#include<sstream>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int dt){
        data=dt;
        left=right=NULL;
    }
};

vector<vector<int>>paths(Node*);

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
    vector<vector<int>>v=paths(root);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++)
            cout<<v[i][j]<<" ";
        cout<<"#";
    }
    
    return 0;
}

// Function to find all possible paths from root to all leaf nodes.

void getPaths(Node *root,vector<vector<int>>&v,vector<int>&ans){
    if(!root)
        return;

    ans.push_back(root->data);
    getPaths(root->left,v,ans);
    getPaths(root->right,v,ans);

    if(!root->left && !root->right)
        v.push_back(ans);
    ans.pop_back();
}

vector<vector<int>>paths(Node *root){
    vector<vector<int>>v;
    vector<int>ans;
    
    getPaths(root,v,ans);

    return v;
}
