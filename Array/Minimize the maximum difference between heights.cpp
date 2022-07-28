#include <iostream>
#include <algorithm>
using namespace std;

/*

Given an array arr[] denoting heights of N towers and a positive integer K.

For each tower, you must perform exactly one of the following operations exactly once.

Increase the height of the tower by K.
Decrease the height of the tower by K ( you can do this operation only if the height of the tower is greater than or equal to K)
Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.

*/

int getMinDiff(int[], int, int);

int main()
{

    int n, k;
    cin >> n >> K;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << getMinDiff(arr, n, k) << endl;

    return 0;
}

// METHOD

int getMinDiff(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int result = arr[n - 1] - arr[0];
    int max = arr[n - 1];
    int min = arr[0];

    for (int i = 1; i < n; i++)
    {

        max = std::max(arr[i - 1] + k, arr[n - 1] - k);
        min = std::min(arr[0] + k, arr[i] - k);

        if (min < 0)
            continue;
        else
            result = std::min(result, max - min);
    }
    return result;
}