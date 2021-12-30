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

int diameter(Node*);

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
    int h=diameter(root);
    cout<<h<<endl;
    return 0;
}

// Function to find the diameter or width of the tree.

/* The diameter of a tree (sometimes called the width) is 
   the number of nodes on the longest path between two end nodes. */

int height(Node *root,int &d){

    if(!root)
        return 0;

    int l=height(root->left,d);
    int r=height(root->right,d);

    int h=1+max(l,r);
    d=max(max(h,l+r+1),d);
    
    return h;
}

int diameter(Node *root){
    int d=0;
    height(root,d);
    return d;
}