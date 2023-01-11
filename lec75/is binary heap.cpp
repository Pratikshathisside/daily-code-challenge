class Solution {
    private:
    int iscount(struct Node* tree){
        int cnt;
        if(tree == NULL){
            return 0;
        }
        else{
           cnt = 1+ iscount(tree->left)+ iscount(tree->right);
        }
        return cnt;
    }
    bool iscbt( struct Node* root, int index,int cnt){
        if(root==NULL){
            return  true;
        }
         if(index>=cnt){
            return false;
        }
        else{
            int left = iscbt(root->left,(2*index)+1,cnt);
            int right = iscbt(root->right, (2*index)+2, cnt );
        return (left && right);
        }
        
    }
    bool ismax(Node* root){
        if(root->left == NULL && root->right == NULL ){
            return true;
        }
        
        if(root->right==NULL){
            return (root->data>root->left->data);
        }
        else{
            int left = ismax(root->left);
            int right = ismax(root->right);
            return (left && right && (root->data>root->left->data && root->data >root->right->data));
        }
    }
  public:
   
    bool isHeap(struct Node* tree) {
        // code here
        int index = 0;
        int cnt = iscount(tree);
        return(iscbt(tree,index,cnt)&& ismax(tree));
    }
};
