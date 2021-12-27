#include<iostream>
#include<vector>
#include<sstream>
#include<string>
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
    if(s.length()==0)
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

void printList(Node *head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}

Node* addTwoLists(Node *,Node*);

int main(){

    string s1,s2;
    getline(cin,s1);
    Node *first=buildList(s1);
    getline(cin,s2);
    Node *second=buildList(s2);
    Node *sum=addTwoLists(first,second);
    printList(sum);

    return 0;
}



// Function to add two numbers represented by linked list

// 1. By reversing Linked list

/*
Node* reverse(Node* head){
    Node *prev = NULL, *curr = head, *next = NULL;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
    
Node* addTwoLists(Node* first,Node* second)
{
    Node* l1 = reverse(first),*l2 = reverse(second);
        
    Node* temp=new Node(-1),*temp2 = temp;
        
    int carry = 0;
    while(l1 || l2 || carry==1){
        int sum = 0;
        if(l1){
            sum += l1->data;
            l1   = l1->next;
        }
        if(l2){
            sum += l2->data;
            l2   = l2->next;
        }
        sum  += carry;
        carry = sum/10;
            
        Node* ptr=new Node(sum%10);
            
        temp2->next = ptr;
        temp2 = temp2->next;
    }
    Node* ans = reverse(temp->next);

    return ans;
}
*/

// 2. Without reversing Linked list


Node* addFirst(Node *res,int val){
        
    if(!res)
        res=new Node(val);
    else{
        Node *cnext=res;
        res=new Node(val);
        res->next=cnext;
    }
        
    return res;
}    

int addHelper(Node *first,int p1,Node *second,int p2,Node **res){
        
    if(!first && !second)
        return 0;
            
    int data=0;
    if(p1>p2){
        int oc=addHelper(first->next,p1-1,second,p2,res);
        data=first->data+oc;
    }
    else if(p2>p1){
        int oc=addHelper(first,p1,second->next,p2-1,res);
        data=second->data+oc;    
    }
    else{
        int oc=addHelper(first->next,p1-1,second->next,p2-1,res);
        data=first->data+oc+second->data;
    }
    int nd=data % 10;
    int nc=data / 10;
            
    *res=addFirst(*res,nd);
            
    return nc;
}
    
int size(Node *head){
    int n=0;
    while(head){
        head=head->next;
        n++;
    }
    return n;
}
    
Node* addTwoLists(Node* first,Node* second){

    Node *res=NULL;
    int oc=addHelper(first,size(first),second,size(second),&res);
    if(oc>0)
        res=addFirst(res,oc);
    return res;
}