#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct Node
{
    int data;
    Node *next, *prev;
    Node(int dt)
    {
        data = dt;
        next = NULL;
        prev = NULL;
    }
};

Node *buildList(string s)
{
    if (s.length() == 0)
        return NULL;

    vector<string> v;
    istringstream strm(s);
    for (string str; strm >> str;)
        v.push_back(str);

    Node *head = new Node(stoi(v[0]));
    Node *tail = head;
    for (int i = 1; i < v.size(); i++)
    {
        tail->next = new Node(stoi(v[i]));
        tail->next->prev = tail;
        tail = tail->next;
    }
    return head;
}

Node *revListInGroupOfGivenSize(Node *, int);

void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{

    string s;
    getline(cin, s);
    Node *head = buildList(s);
    int N;
    cin >> N;
    head = revListInGroupOfGivenSize(head, N);
    printList(head);

    return 0;
}

// Function to reverse the doubly linked list in the group of given size

// METHOD - 1 (Mine)

Node *revListInGroupOfGivenSize(Node *head, int k)
{

    if (!head)
        return head;

    Node *prev = NULL, *cnext = NULL, *curr = head;
    for (int i = 0; i < k && curr; i++)
    {
        cnext = curr->next;
        curr->next = prev;
        curr->prev = cnext;
        prev = curr;
        curr = cnext;
    }
    prev->prev = NULL;
    Node *newHead = revListInGroupOfGivenSize(cnext, k);
    head->next = newHead;
    if (newHead)
        newHead->prev = head;

    return prev;
}

// METHOD - 2 (GFG)
/*
Node *revListInGroupOfGivenSize(Node *head,int k){

    if(!head)
        return NULL;

    head->prev=NULL;
    Node *prv=NULL,*curr=head,*newHead=NULL;
    int count=0;
    while(curr && count < k){
        prv=curr->prev;
        newHead=curr;
        curr->prev=curr->next;
        curr->next=prv;
        curr=curr->prev;
    }

    if(count >= k){
        Node *rest=revListInGroupOfGivenSize(curr,k);
        head->next=rest;
        if(rest)
            rest->prev=head;
    }

    return newHead;
}
*/