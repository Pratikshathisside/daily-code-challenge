
class node{
public:
int data; 
int row; int col;
node(int d,int r, int c){
    data = d; 
    row = r; col = c;
}
};
class compare{
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};

class Solution {

public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini = INT_MAX; int maxi = INT_MIN;
        priority_queue <node* ,vector<node*>,compare> minheap;
        for(int i = 0; i<nums.size();i++){
            int element = nums[i][0];
            mini = min(element,mini);
            maxi = max(maxi,element);
minheap.push(new node(element, i ,0));

        }
        int start = mini; int end = maxi;
        while(!minheap.empty()){
            node* temp = minheap.top();
            minheap.pop();
            mini = temp->data;
            if(maxi - mini< end - start){
                end = maxi; 
                start = mini;
            }
            if(temp->col +1 <nums[temp->row].size()){
maxi = max(maxi,nums[temp->row][temp->col+1]);
minheap.push(new node(nums[temp->row][temp->col +1],temp->row,temp->col+1));

            }
            else{
                break;
            }
        }
        if(maxi ==INT_MIN || mini==INT_MAX){
            return {-1,-1};
        }
        

        vector<int>ans;
        ans.push_back(start);
        ans.push_back(end);
        return ans;


    }
};
