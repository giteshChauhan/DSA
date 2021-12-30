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

vector<int> diagonal(Node *);

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
    vector<int>res=diagonal(root);
    for(auto i: res)
        cout<<i<<" ";
    
    return 0;
}


// Function to traverse the binary tree diagonally

vector<int> diagonal(Node *root){

    vector<int>res;
    if(!root)
        return res;

    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        
        Node *curr=q.front();
        q.pop();

        while(curr){
            res.push_back(curr->data);
            if(curr->left)
                q.push(curr->left);
            curr=curr->right;
        }
    }

    return res;
}