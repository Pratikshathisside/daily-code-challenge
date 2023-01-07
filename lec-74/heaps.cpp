#include <iostream>
using namespace std;

class Heap
{
public:
   int arr[100];
   int size;

   // constructor
   Heap()
   {
      arr[0] = -1;
      size = 0;
   }
   void insert(int val)
   {
      size = size + 1;
      int index = size;
      arr[index] = val;
      while (index > 1)
      {
         int parent = index / 2;
         if (arr[parent] < arr[index])
         {
            swap(arr[parent], arr[index]);
            parent = index;
         }
         else
         {
            return;
         }
      }
   }
   void print(int arr[])
   {
      for (int i = 1; i <= size; i++)
      {
         cout << arr[i] << " ";
      }
      cout << endl;
   }
};
int main()
{
   Heap h;

   h.insert(1);

   h.insert(33);
   h.insert(35);
   h.insert(3);

   h.insert(43);
   h.insert(53);
   h.insert(6);
   h.print(h.arr);
}
