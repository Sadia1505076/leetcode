// Given the root of a binary tree, invert the tree, and return its root.

// Example 1:
// Input: root = [4,2,7,1,3,6,9]
// Output: [4,7,2,9,6,3,1]


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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> visited;
        visited.push(root);
        while (!visited.empty()) {
            TreeNode* front = visited.front();
            visited.pop();
            if (front != NULL) {
                TreeNode* temp = front->left;
                front->left = front -> right;
                front -> right = temp;
                if (front -> left != NULL) visited.push(front -> left);
                if (front -> right != NULL) visited.push(front -> right);
            }
        }
        return root;
    }
};