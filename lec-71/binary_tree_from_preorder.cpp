
BinaryTreeNode<int>* solve(vector<int> &preorder,int mini, int maxi, int& i){
    if(i>=preorder.size()){
        return NULL;
    }
    if(preorder[i]<mini|| preorder[i]>maxi){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[i++]);
    root->left = solve(preorder,mini,root->data,i );
    root->right = solve(preorder, root->data, maxi,i);
    return root;
    
} 
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    // Write your code here.
    int i = 0;
    BinaryTreeNode<int>* ans = solve(preorder, INT_MIN,INT_MAX,i);
    return ans;
}
