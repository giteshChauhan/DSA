#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int dt){
        data=dt;
        next=NULL;
    }
};

Node* buildList(string s){
    if(s.length() == 0)
        return;
    
    vector<string>v;
    istringstream strm(s);
    for(string str;strm>>str;)
        v.push_back(str);

    Node *head=new Node(stoi(v[0]));
    Node*tail=head;
    for(int i=1;i<v.size();i++){
        tail->next=new Node(stoi(v[i]));
        tail=tail->next;
    }
    return head;
}

long long multiplyTwoLists(Node*,Node*);

int main(){

    string s1,s2;
    getline(cin,s1);
    Node *l1=buildList(s1);
    getline(cin,s2);
    Node*l2=buildList(s2);
    long long mul=multiplyTwoLists(l1,l2);
    cout<<mul;

    return 0;
}



// Function to multiply two numbers represented by linked list

// Note: The output could be large take modulo 10^9 + 7.

long long multiplyTwoLists(Node *l1,Node *l2){

    long long mod=1000000007;
    long long num1=0,num2=0;
    
    while(l1 || l2){
        if(l1){
            num1=((num1%mod)*10)%mod + l1->data;
            l1=l1->next;
        }
        if(l2){
            num2=((num2%mod)*10)%mod + l2->data;
            l2=l2->next;
        }
    }

    return ((num1%mod) * (num2%mod))%mod;
}