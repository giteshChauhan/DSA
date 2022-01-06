#include<iostream>
#include<sstream>
#include<string>
#include<stack>
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

Node *buildTree(string s,int,int);

void printTree(Node *root){
    if(root){
        cout<<root->data<<" ";
        printTree(root->left);
        printTree(root->right);
    }
}

int main(){
    string s;
    getline(cin,s);
    Node *root=buildTree(s,0,s.length()-1);
    printTree(root);

    return 0;
}

// Function to construct a binary tree from a string with bracket representation.

int findIndex(string s,int si,int ei){
    if(si > ei)
        return -1;
    
    stack<char>st;

    for(int i=si;i<=ei;i++){
        if(s[i] == '(')
            st.push(s[i]);
        else if(s[i] == ')'){
            if(st.top() == '('){
                st.pop();
                if(st.empty())
                    return i;
            }
        }
    }

    return -1;
}

Node *buildTree(string s,int si,int ei){
    if(si > ei)
        return NULL;

    Node *root=new Node(s[si]-'0');
    int index=-1;

    if(si+1 <= ei && s[si+1] == '(')
        index=findIndex(s,si+1,ei);

    if(index != -1){
        root->left=buildTree(s,si+2,index-1);
        root->right=buildTree(s,index+2,ei-1);
    }

    return root;
}