/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode*solve(TreeNode* root,int val){
    if(root==NULL) return new TreeNode(val);
    if(val<root->val){
        root->left=solve(root->left,val);
    }
    else{
        root->right=solve(root->right,val);
    }
    return root ;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode*root=NULL;
        for( int i =0 ;i<preorder.size();i++){
            root=solve(root,preorder[i]);
        }
        return root ;
    }
};