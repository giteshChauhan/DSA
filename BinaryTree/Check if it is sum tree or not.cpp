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

bool isSumTree(Node*);

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
    bool b=isSumTree(root);
    cout<<b<<endl;

    return 0;
}

// Funtion to check weather a given binary tree is a sum tree or not.

int traverse(Node*root,bool &ans){
    if(!root || ans == 0)
        return 0;
    if(!root->left && !root->right)
        return root->data;
        
    int sum=traverse(root->left,ans)+traverse(root->right,ans);
        
    if(sum != root->data)
        ans=0;
        
    return sum+root->data;
}
    
bool isSumTree(Node* root){
    bool ans=1;
    traverse(root,ans);
    return ans;
}