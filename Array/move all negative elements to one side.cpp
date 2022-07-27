#include <iostream>
#include <queue>
using namespace std;

// Function to move all negative elements to the last of an array.
// Note : Order of elements should be  maintained

void swap(int &i, int &j)
{
    int temp = i;
    i = j;
    j = temp;
}

void rearrange(int arr[], int n)
{
    int j = 0;
    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
        else
        {
            q.push(arr[i]);
        }
    }

    while (j < n)
    {
        arr[j] = q.front();
        q.pop();
    }
}

int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    rearrange(arr, n);
    for (auto i : arr)
        cout << i << " ";

    return 0;
}
