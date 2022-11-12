queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    //pop first k and put into stackk
    stack<int> s;
    for(int i =0 ;i<k ; i++){
        int val = q.front();
        q.pop();
        s.push(val);
    }
    //fetch from stack and put into q;
    while(!s.empty()){
        int val = s.top();
        s.pop();
        q.push(val);
    }
    //step 3: fetch first n-k element from q and push bavk
    int t = q.size()-k;
    while(t--){
        int val = q.front();
        q.pop();
        q.push(val);
        
    }
    return q;
}
