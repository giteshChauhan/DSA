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
        left=right=NULL;
    }

};

bool isIsomorphic(Node *,Node*);

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
    string s1,s2;
    getline(cin,s1);
    Node *root1=buildTree(s1);
    getline(cin,s2);
    Node *root2=buildTree(s2);
    cout<<isIsomorphic(root1,root2);
    return 0;
}


// Function to check wheather given two trees are isomorphic or not.

/*
    Two trees are called isomorphic if one of them can be obtained from other by a series of flips, i.e.
    by swapping left and right children of a number of nodes. Any number of nodes at any level can have
    their children swapped. Two empty trees are isomorphic.
*/

bool isIsomorphic(Node *root1,Node *root2){

    if(!root1 && !root2)
        return 1;
    if(!root1 || !root2)
        return 0;
    if(root1->data != root2->data)
        return 0;
        
    return((isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right,root2->right))
            || (isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right,root2->left)));
}