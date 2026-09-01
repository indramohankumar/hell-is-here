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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        if(root==NULL) return ans;
        bool lefttoright=true;
        while(!q.empty()){
            int n=q.size();
            vector<int> level(n);
            for(int i =0;i<n;i++){
                TreeNode*Node=q.front();
                q.pop();
                int index;
                if(lefttoright) {
                index =i ;
                }
                else {
                    index=n-i-1;
                }
                level[index]=Node->val;
                if(Node->left) q.push(Node->left);
                if(Node->right) q.push(Node->right);

            }
            ans.push_back(level);
            lefttoright=!lefttoright;
        }
        return ans  ;
        
    }
};