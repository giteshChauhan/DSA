#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<string>
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
};

vector<int>topView(Node*);

Node *buildTree(string s){
    if(s.length() == 0 || s[0]=='N')
        return NULL;

    vector<string>v;
    istringstream strm(s);
    for(string str;strm>>str;)
        v.push_back(str);

    Node *root=new Node(stoi(v[0]));
    queue<Node*>q;
    q.push(root);
    int i=1;
    while(!q.empty() && i < v.size()){
        Node *temp=q.front();
        q.pop();
        if(v[i] != "N"){
            temp->left=new Node(stoi(v[i]));
            q.push(temp->left);
        }
        i++;
        if(i >= v.size())
            break;
        if(v[i] != "N"){
            temp->right=new Node(stoi(v[i]));
            q.push(temp->right);
        }
        i++;
    }

    return root;
}

int main(){
    string s;
    getline(cin,s);
    Node *root=buildTree(s);
    vector<int>top=topView(root);
    for(auto i:top) cout<<i<<" ";
    return 0;
}


// Function to find the top view of the given binary tree

vector<int>topView(Node *root){

    map<int,int>m;
    queue<pair<Node*,int>>q;
    q.push({root,0});

    while(!q.empty()){
        Node *currNode=q.front().first;
        int h=q.front().second;
        q.pop();

        if(currNode->left)  q.push({currNode->left,h-1});
        if(currNode->right) q.push({currNode->right,h+1});

        if(m.find(h) == m.end())
            m[h]=currNode->data;

    }

    vector<int>res;
    for(auto it:m)
        res.push_back(it.second);

    return res;
}