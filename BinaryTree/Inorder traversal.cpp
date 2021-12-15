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



// Solution class

class Solution{
    vector<int>res;
public:

// Function to traverse a tree inOrderly (recursively)

    vector<int>inOrder(Node *root){
        if(root){
            inOrder(root->left);
            res.push_back(root->data);
            inOrder(root->right);
        }
        return res;
    }
};



int main(){
    string str;
    getline(cin,str);
    Node *root=buildTree(str);
    Solution obj;
    vector<int>v=obj.inOrder(root);
    for(auto i:v) cout<<i<<" ";
    return 0;
}


