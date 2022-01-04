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

int findDist(Node *,int,int);

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
    int n1,n2;
    cin>>n1>>n2;
    int dist=findDist(root,n1,n2);
    cout<<dist;
    
    return 0;
}


// Function to find the minimum distance between two nodes.

int traverse(Node *root,int a,int b,int &ans){
    if(!root || ans>0)
        return 0;
    
    int l=traverse(root->left,a,b,ans);
    int r=traverse(root->right,a,b,ans);

    if(root->data == a || root->data == b){
        if(l) ans=l;
        else if(r)  ans=r;
        return 1;
    }

    if(l && r) ans=l+r;
    else if(l) return l+1;
    else if(r) return r+1;
    return 0;
}

int findDist(Node *root,int a,int b){
    if(a == b) return 0;
    int ans=0;
    traverse(root,a,b,ans);
    return ans;
}