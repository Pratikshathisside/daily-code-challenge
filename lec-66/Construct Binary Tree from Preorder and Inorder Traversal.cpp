class Solution {
    private:
    int findpos(vector<int>in, int element ){
        for (int i =0; i<in.size();i++){
            if(element == in[i]){
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int>preorder, vector<int>inorder,int &index,int instart, int inend,int size){
        //base case 
        if(instart>inend || index>size){
            return NULL;
        }
        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        int pos = findpos(inorder,element);
        
        //right n left chosing
        root->left = solve(preorder,inorder,index,instart,pos-1,size);
        root->right = solve(preorder,inorder,index,pos+1,inend,size);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        int instart = 0;
        int inend = inorder.size();
        int size = preorder.size();
        TreeNode* ans = solve(preorder,inorder,index,instart,inend-1,size);
        return ans;
    }
};
