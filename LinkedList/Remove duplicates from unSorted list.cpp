#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_set>
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

Node *removeDuplicates(Node *);

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

int main()
{

    string s;
    getline(cin, s);
    Node *head = buildList(s);
    head = removeDuplicates(head);
    printList(head);

    return 0;
}

// Function to remove duplicates from an Un-sorted LinkedList

Node *removeDuplicates(Node *head)
{

    if (!head || !head->next)
        return head;

    unordered_set<int> seen;
    Node *curr = head, *prev = NULL;

    while (curr != NULL)
    {

        if (seen.find(curr->data) != seen.end())
        {
            prev->next = curr->next;
            delete (curr);
        }
        else
        {
            seen.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }

    return head;
}