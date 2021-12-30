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

vector<int>zigZagTraversal(Node*);

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
    vector<int>res=zigZagTraversal(root);
    for(auto i:res)
        cout<<i<<" ";
    
    return 0;
}



// Funtion to traverse the binary tree in zig-zag fashion 

vector <int> zigZagTraversal(Node* root){

    vector<int>res;
    Node *curr=NULL;
    stack<Node*>currLevel,nextLevel;
    currLevel.push(root);
    bool leftToRight=true;
    	
    while(!currLevel.empty()){
        Node *curr=currLevel.top();
        currLevel.pop();

        if(curr){
            res.push_back(curr->data);

            if(leftToRight){
                if(curr->left)
                    nextLevel.push(curr->left);
                if(curr->right)
                    nextLevel.push(curr->right);
            }else{
                if(curr->right)
                    nextLevel.push(curr->right);
                if(curr->left)
                    nextLevel.push(curr->left);
            }
        }

        if(currLevel.empty()){
            swap(currLevel,nextLevel);
            leftToRight = !leftToRight;
        }
    }
    	
    return res;
}


