#include <iostream>
#include <string>
using namespace std;

// Function to find the first non-repeating character from the stream of characters.
// METHOD 1 - Doubly linked list approach.

/*
    Given an input stream of A of n characters consisting only of lower case alphabets.
    The task is to find the first non repeating character, each time a character is inserted to the stream.
    If there is no such character then append '#' to the answer.
*/

struct Node
{
    char data;
    Node *next, *prev;
    Node(char ch)
    {
        data = ch;
        next = NULL;
        prev = NULL;
    }
};

bool isEmpty(Node *head)
{
    return (head ? 0 : 1);
}

void addLast(Node **head, char ch)
{
    if (!(*head))
        *head = new Node(ch);
    else
    {
        Node *tail = *head;
        while (tail->next)
            tail = tail->next;
        tail->next = new Node(ch);
        tail->next->prev = tail;
    }
}

void removeFirst(Node **head)
{
    if (!(*head))
        return;
    Node *del = *head;
    if (!(*head)->next)
    {
        *head = NULL;
    }
    else
    {
        *head = (*head)->next;
        del->next = NULL;
        (*head)->prev = NULL;
    }
    delete del;
}

char getFirst(Node *head)
{
    return (head->data);
}

string firstNonRepeating(string a)
{

    int arr[26] = {0};
    Node *head = NULL;
    for (int i = 0; i < a.length(); i++)
    {
        arr[a[i] - 'a']++;

        if (arr[a[i] - 'a'] == 1)
            addLast(&head, a[i]);

        while (isEmpty(head) == 0 && arr[getFirst(head) - 'a'] != 1)
            removeFirst(&head);

        if (isEmpty(head))
            a[i] = '#';
        else
            a[i] = getFirst(head);
    }

    return a;
}

// METHOD - 2 (GFG) : optimal
/*
string FirstNonRepeating(string A){
    int n = A.size();
    vector<int>f(26, 0);
    vector<int>last(26, -1);
    for(int i = 0; i < A.size(); i++){
        if(last[A[i] - 'a'] == -1)
            last[A[i] - 'a'] = i;
    }
    string ans="";
    for(int i = 0; i < A.size(); i++){
        f[A[i] - 'a']++;
        char ch = '#';
        int x = A.size() + 1;
        for(int j = 0; j < 26; j++){
            if(f[j] == 1 and x > last[j]){
                ch = char(j + 'a');
                x = last[j];
            }
        }
        ans += ch;
    }
    return ans;
}
*/