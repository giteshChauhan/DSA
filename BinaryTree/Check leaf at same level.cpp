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

bool check(Node *);

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
    bool c=check(root);
    cout<<c;
    
    return 0;
}


// Function to check if all leaves are at the same level or not.

int height(Node *root,bool &sameLevel){
    if(!root)
        return 0;
    
    int l=height(root->left,sameLevel);
    int r=height(root->right,sameLevel);

    if(l && r && l!=r)
        sameLevel=false;
    
    return(max(l,r)+1);
}

bool check(Node *root){
    bool isSameLevel=true;
    height(root,isSameLevel);
    return isSameLevel;
}