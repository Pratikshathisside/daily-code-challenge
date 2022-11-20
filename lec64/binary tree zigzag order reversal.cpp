class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       
            vector<vector<int>> result;
        //base caase
        if(root==NULL){
            return result;
        }
    
      
        queue<TreeNode*>q;
        q.push(root);
        bool lefttoright = true;
         while(!q.empty()){
             
               int size = q.size();
              vector<int> ans(size);
            for(int i = 0; i<size;i++){
                  TreeNode* qfront = q.front();
                   q.pop();
                   int index= lefttoright?i:size-1-i;
                 //storing the values 
                    ans[index] =  qfront->val;
            
             
                 if(qfront->left)
                     q.push(qfront->left);
                 
                            if(qfront->right)
                                q.push(qfront->right);
                            
                            
            }
                            //direction change
                            lefttoright = !lefttoright;
                            
                             result.push_back(ans);
                            }
    
          return result;                  
    }
};
