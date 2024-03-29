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

Node *compute(Node *);

int main()
{

    string s;
    getline(cin, s);
    Node *head = buildList(s);
    head = compute(head);
    printList(head);

    return 0;
}

// Function to delete nodes heaving greater value on right

Node *reverse(Node *head)
{

    if (!head || !head->next)
        return head;

    Node *cnext = NULL, *prev = NULL;
    while (head)
    {
        cnext = head->next;
        head->next = prev;
        prev = head;
        head = cnext;
    }

    return prev;
}

Node *compute(Node *head)
{

    if (!head || !head->next)
        return head;

    head = reverse(head);

    head = reverse(head);
    Node *prev = NULL, *curr = head;
    int max = INT_MIN;

    while (curr)
    {
        if (curr->data >= max)
        {
            max = curr->data;
            prev = curr;
        }
        else
        {
            prev->next = curr->next;
            delete curr;
        }
        curr = prev->next;
    }

    return (reverse(head));
}