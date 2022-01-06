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

int largestSubtreeSum(Node *);

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
    cout<<largestSubtreeSum(root);
    
    return 0;
}

// Function to find the largest subtree sum in a binary tree.

int largestSum(Node *root,int &ans){

    if(!root)
        return 0;

    int sum=root->data+largestSum(root->left,ans)+largestSum(root->right,ans);
    ans=max(ans,sum);

    return sum;
}

int largestSubtreeSum(Node *root){
    if(!root)
        return 0;

    int ans=INT_MIN;
    largestSum(root,ans);

    return ans;
}