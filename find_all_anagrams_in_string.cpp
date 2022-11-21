class Solution {
    private:
    bool qual(vector<int>count1, vector<int>count2){
        for(int i = 0; i<26;i++){
            if(count1[i]!=count2[i]){
                return 0;
            }
        }
        return 1;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        int ss = s.size();
        int ps = p.size();
        vector<int>ans;
        vector<int>count1(26,0);
        vector<int>count2(26,0);
        
        for(int i = 0; i<ps;i++){
            count1[p[i]-'a'] ++;
        }
       int i =0;
        int windowsize = p.size();
        while(i<windowsize && i<s.size()){
            int index = s[i] -'a';
            count2[index]++;
            i++;
            
        }
        if (qual(count1,count2)){
            ans.push_back(i-p.size());
        }
        while(i<s.size()){
            char newchar = s[i];
            int index = newchar -'a';
            count2[index]++;
            //deleting old char
            char oldchar = s[i-windowsize];
            index = oldchar -'a';
            count2[index]--;
            i++;
            if (qual(count1,count2)){
                ans.push_back(i-p.size());
            }
        }
         return ans;
    }
};
