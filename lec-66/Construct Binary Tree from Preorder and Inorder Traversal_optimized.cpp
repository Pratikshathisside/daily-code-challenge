class Solution {
    //this tym with o(1) space using to find the index of the element.
    private:
    void createmapping(vector<int>in, map<int,int>&nodetoindex, int size){
        for(int i=  0; i<in.size(); i++){
            nodetoindex[in[i]]= i;
        }
    }
    TreeNode* solve(vector<int>preorder, vector<int>inorder,int &index,int instart, int inend,int size,map<int,int>&node){
        //base case 
        if(instart>inend || index>size){
            return NULL;
        }
        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        int pos = node[element];
        
        //right n left chosing
        
        root->left = solve(preorder,inorder,index,instart,pos-1,size,node);
        root->right = solve(preorder,inorder,index,pos+1,inend,size,node);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        int instart = 0;
       map<int,int> nodetoindex;
        int inend = inorder.size();
        int size = preorder.size();
        createmapping(inorder, nodetoindex, size);
        TreeNode* ans = solve(preorder,inorder,index,instart,inend-1,size,nodetoindex);
        return ans;
    }
};
