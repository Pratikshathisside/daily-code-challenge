#include <iostream>
#include <queue>
using namespace std;

int main()
{
    deque<int> d;
    d.push_front(12);
    d.push_front(33);
    d.push_back(134);
    cout << d.front() << endl;
    cout << d.back();
    d.pop_back();
    d.pop_front();
    if (d.empty())
    {
        cout << " Doubly ended queue is empty";
    }
    else
    {
        cout << "";
    }
}
