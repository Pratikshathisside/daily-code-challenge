queue<int> rev(queue<int> q)
{
    // add code here.
    stack<int>s;
    while(!q.empty()){
        int ele = q.front();
        q.pop();
        s.push(ele);
    }
    while(!s.empty()){
        int el = s.top();
        s.pop();
        q.push(el);
    }
    return q;
}
