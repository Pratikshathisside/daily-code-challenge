#include <iostream>
using namespace std;

void insert_sort(int arr[], int n)
{

    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int prev = i - 1;
        while (prev >= 0 && arr[prev] > curr)
        {
            arr[prev + 1] = arr[prev];

            prev = prev - 1;
        }
        arr[prev + 1] = curr;
    }
}
int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    insert_sort(arr, 5);
    int n = sizeof(arr) / sizeof(int);
    for (auto x : arr)
    {
        cout << x;
    }
}
