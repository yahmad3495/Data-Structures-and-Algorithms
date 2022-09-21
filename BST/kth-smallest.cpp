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
    
    vector<int> inorder(TreeNode* root, vector<int>& arr) {
        if (root == nullptr) {
            return arr;
        }
        
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
        return arr;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> helper;
        vector<int> sol = inorder(root, helper);
        return sol[k - 1];
    }
};