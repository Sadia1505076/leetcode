// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> traversal;
        queue<TreeNode*> bfs_queue;
        vector<int> nodeValue;

        TreeNode* emptyTreeNode = new TreeNode(-9999);
        bfs_queue.push(root);
        bfs_queue.push(emptyTreeNode);

        while(!bfs_queue.empty()) {
            TreeNode* front = bfs_queue.front();
            if (front != NULL) {
                nodeValue.push_back(front -> val);
                if (front -> left != NULL) {
                    bfs_queue.push(front -> left);
                }
                if (front -> right != NULL) {
                    bfs_queue.push(front -> right);
                }
                bfs_queue.pop();
                if (!bfs_queue.empty() && bfs_queue.front() != NULL && bfs_queue.front() -> val == -9999) {
                    traversal.push_back(nodeValue);
                    nodeValue.clear();
                    TreeNode* emptyTreeNode = new TreeNode(-9999);
                    bfs_queue.push(emptyTreeNode);
                    bfs_queue.pop();
                }
            }
            else bfs_queue.pop();
        }
        return traversal;
    }
};