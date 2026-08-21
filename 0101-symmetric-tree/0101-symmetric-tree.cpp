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
    bool solver(TreeNode* root, TreeNode* left, TreeNode* right)
    {
        if(root==nullptr) return true;
        if(left == nullptr && right==nullptr) return true;
        if(left == nullptr || right==nullptr) return false;
        if(left->val != right->val) return false;
        return solver(root, left->left, right->right) && solver(root, left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return solver(root, root->left, root->right);

    }
};