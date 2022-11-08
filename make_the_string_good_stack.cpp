class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        char ch;
        string ans ="";
        for(int i= 0;i<s.length();i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                ch = st.top();
                if(isupper(s[i])){
                    if(islower(ch) && toupper(ch)==s[i]){
                        st.pop();
                    }
                    else{
                        st.push(s[i]);
                    }
                }
                if(islower(s[i])){
                    if(isupper(ch) && tolower(ch)==s[i]){
                        st.pop();
                    }
                    else{
                        st.push(s[i]);
                    }
                }
                
                
            }
            
        }
        while(!st.empty()){
            ans = ans + st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
