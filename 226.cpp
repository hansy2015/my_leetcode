/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  /*
    递归解决
  */
  TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) {
      return NULL;
    }
    invertTree(root->left);
    invertTree(root->right);
    swap(root->left, root->right);
    return root;
  }
};