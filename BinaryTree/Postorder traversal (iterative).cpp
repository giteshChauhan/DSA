#include<iostream>
#include<vector>
#include<queue>
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
public:

// Function to traverse a tree PostOrderly (iterative).

    vector<int>inOrder(Node *root){
        vector<int>res;
        if(!root)
            return res;
        stack<Node*>st1,st2;
        st1.push(root);
        while(!st1.empty()){
            Node *currNode=st1.top();
            st1.pop();
            st2.push(currNode);
            if(currNode->left)
                st1.push(currNode->left);
            if(currNode->right)
                st1.push(currNode->right);
        }

        while(!st2.empty()){
            Node *currNode=st2.top();
            st2.pop();
            res.push_back(currNode->data);
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
