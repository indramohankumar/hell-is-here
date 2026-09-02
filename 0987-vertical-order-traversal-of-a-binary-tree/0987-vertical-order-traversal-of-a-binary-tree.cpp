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
    vector<vector<int>> verticalTraversal(TreeNode* root) {


        map<int, vector<pair<int,int>>> nodes;

        queue<pair<TreeNode*, pair<int,int>>> q;

        q.push({root, {0, 0}});

        while(!q.empty()) {

            pair<TreeNode*, pair<int,int>> p = q.front();
            q.pop();

            TreeNode* node = p.first;
            int x = p.second.first;
            int y = p.second.second;

            nodes[x].push_back({y, node->val});

            if(node->left != NULL) {
                q.push({node->left, {x - 1, y + 1}});
            }

            if(node->right != NULL) {
                q.push({node->right, {x + 1, y + 1}});
            }
        }

        vector<vector<int>> ans;

        for(auto it = nodes.begin(); it != nodes.end(); it++) {

            vector<pair<int,int>>& v = it->second;

            sort(v.begin(), v.end());

            vector<int> temp;

            for(int i = 0; i < v.size(); i++) {
                temp.push_back(v[i].second);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
        
    