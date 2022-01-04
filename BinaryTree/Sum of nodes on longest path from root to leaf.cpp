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

int sumOfLongRootToLeafPath(Node*);

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
    int s=sumOfLongRootToLeafPath(root);
    cout<<s<<endl;

    return 0;
}


// Function to find the sum of nodes on the longest path from root to leaf node.

void traverse(Node *root,int level,int sum,int &maxLevel,int &ans){

    if(!root)   return;
        
    sum += root->data;
    if(level > maxLevel){
        ans=sum;
        maxLevel=level;
    }else if(level == maxLevel)
        ans=max(ans,sum);
        
    traverse(root->left,level+1,sum,maxLevel,ans);
    traverse(root->right,level+1,sum,maxLevel,ans);
}

int sumOfLongRootToLeafPath(Node *root){
    int maxLevel=0,ans=INT_MIN;
    traverse(root,1,0,maxLevel,ans);
    return ans;
}