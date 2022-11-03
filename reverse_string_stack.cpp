#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<char> s;
    string str = "pratiksha";
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        s.push(ch);
    }
    string ans = "";
    while (!s.empty())
    {
        char v = s.top();
        ans.push_back(v);
        s.pop();
    }
    cout << ans;
}
