#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int dt)
    {
        data = dt;
        next = NULL;
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
        tail = tail->next;
    }

    return head;
}

void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node *segregate(Node *);

int main()
{

    string s;
    getline(cin, s);
    Node *head = buildList(s);
    head = segregate(head);
    printList(head);

    return 0;
}

// Function to sort Linked list containing 0s 1s and 2s

Node *segregate(Node *head)
{

    Node *zeroH = new Node(-1), *zeroT = zeroH, *oneH = new Node(-1), *oneT = oneH, *twoH = new Node(-1), *twoT = twoH;

    while (head)
    {
        if (head->data == 0)
        {
            zeroT->next = head;
            zeroT = head;
        }
        else if (head->data == 1)
        {
            oneT->next = head;
            oneT = head;
        }
        else
        {
            twoT->next = head;
            twoT = head;
        }
        head = head->next;
    }

    twoT->next = NULL;
    oneT->next = twoH->next;
    zeroT->next = oneH->next ? oneH->next : twoH->next;
    head = zeroH->next;

    return head;
}