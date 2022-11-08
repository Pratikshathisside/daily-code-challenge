#include <iostream>
using namespace std;

// sort element in increasing order
int bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j <= n - i - 1; j++)
        {
            /* code */
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
int print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    bubble_sort(arr, 5);
    int n = sizeof(arr) / sizeof(int);
    for (auto x : arr)
    {
        cout << x;
    }
    print(arr, n);
    return 0;
}