class compare{
        public:
        bool operator()(ListNode* a, ListNode *b){
            return a->val >b->val;

        }
    } ;
class Solution {
 
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> minheap;
        for(ListNode* i:lists){
            if(i!=NULL){
                minheap.push(i);
            }
        }
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(minheap.size()>0){
            ListNode* top = minheap.top();
            minheap.pop();
            if(top->next!=NULL){
                minheap.push(top->next);
            }
            if(head==NULL){
                head = top;
                tail = top;
            }
            else{
                tail->next = top;
                tail = top; 
            }
        }
return head;
    }
};
