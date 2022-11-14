#include <iostream>
#include <queue>
using namespace std;

int solve(int *arr, int n, int k)
{
    deque<int> maxi(k);
    deque<int> mini(k);

    // for addition of first k elements
    for (int i = 0; i < n; i++)
    {
        while (arr[maxi.back()] <= arr[i] && !maxi.empty())
        {
            maxi.pop_back();
        }
        while (arr[mini.back()] >= arr[i] && !mini.empty())
        {
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans = 0;
    for (int i = k; i < n; i++)
    {
        ans += (arr[mini.front()] + arr[maxi.front()]);
        // next window
        // removal
        while (i - maxi.front() >= k)
        {
            maxi.pop_front();
        }
        while (i - mini.front() >= k)
        {
            mini.pop_front();
        }
        // addition
        while (arr[maxi.back()] <= arr[i] && !maxi.empty())
        {
            maxi.pop_back();
        }
        while (arr[mini.back()] >= arr[i] && !mini.empty())
        {
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }
    // considering last window
    ans += (arr[mini.front()] + arr[maxi.front()]);
    return ans;
}
int main()
{
    int arr[7] = {
        2,
        -5,
        -1,
        7,
        -3, -1, -2};
    cout << solve(arr, 7, 4);
    return 0;
}
