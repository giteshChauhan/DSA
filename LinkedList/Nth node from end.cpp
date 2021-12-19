#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int dt){
        data=dt;
        next=NULL;
    }
};

Node *buildList(string s){
    if(s.length() == 0)
        return NULL;
    
    vector<string>v;
    istringstream strm(s);
    for(string str;strm>>str;)
        v.push_back(str);

    Node *head=new Node(stoi(v[0]));
    Node *tail=head;
    for(int i=1;i<v.size();i++){
        tail->next=new Node(stoi(v[i]));
        tail=tail->next;
    }

    return head;
}

int getNthFromLast(Node*,int);

int main(){
    string s;
    getline(cin,s);
    Node *head=buildList(s);
    int n;
    cin>>n;
    int nFromBack=getNthFromLast(head,n);
    cout<<nFromBack<<endl;

    return 0;
}



//Function to find the data of nth node from the end of a linked list.

int getNthFromLast(Node *head, int n)
{
    if(!head)
        return -1;

    Node *p1=head,*p2=head;
       
    int k=n,l=1;
    while(p1->next){
        if(k>1){
         p1=p1->next;
        k--;
        l++;
        }
        else{
            p1=p1->next;
            p2=p2->next;
        }
    }
    if(n>l)
    return -1;
    return(p2->data);
    
}
