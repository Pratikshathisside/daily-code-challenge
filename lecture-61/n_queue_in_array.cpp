#include <iostream>
using namespace std;

class kqueue
{
public:
    int n;
    int k;
    int freespot;
    int *arr;
    int *next;
    int *front;
    int *rear;

public:
    kqueue(int n, int k)
    {
        this->n = n;
        this->k = k;
        front = new int[k];
        rear = new int[k];
        for (int i = 0; i < k; i++)
        {
            rear[i] = -1;
            front[i] = -1;
        }
        arr = new int[n];
        next = new int[n];
        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;

        freespot = 0;
    }
    void enqueue(int data, int qn)
    {
        // overflow
        if (freespot == -1)
        {
            cout << "space is not available";
            return;
        }
        else
        {
            // find first free index
            int index = freespot;
            // update freespot
            freespot = next[index];
            // check whether first element or not
            if (front[qn - 1] == -1)
            {
                front[qn - 1] = 0;
            }
            else
            {
                // link new ele to prev
                next[rear[qn - 1]] = index;
            }
            // update next;
            next[index] = -1;
            // update rear
            rear[qn - 1] = index;
            // arr update
            arr[index] = data;
        }
    }
    int dequeue(int qn)
    {
        // underflow
        if (front[qn - 1] == -1)
        {
            cout << " Queue underflow";
            return -1;
        }
        // find index to pop
        int index = front[qn - 1];
        // front koo aage badhao
        front[qn - 1] = next[index];
        // update next,free bhai tu aage sambhal
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};
int main()
{
    kqueue q(10, 3);
    q.enqueue(10, 1);
    q.enqueue(15, 1);
    q.enqueue(20, 2);
    q.enqueue(25, 1);
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;
    return 0;
}
