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
struct TreeNodeWithLevel {
    TreeNode* treeNode;
    int level;
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> traversal;
        queue<TreeNodeWithLevel*> bfs_queue;
        vector<int> levelValue;
        int levelIndicator = 1;
        TreeNodeWithLevel* rootWithLevel = new TreeNodeWithLevel();
        rootWithLevel -> treeNode = root;
        rootWithLevel -> level = 1;
        bfs_queue.push(rootWithLevel);

        while(!bfs_queue.empty()) {
            TreeNodeWithLevel* front = bfs_queue.front();
            if (front -> level == levelIndicator) {
                levelValue.push_back(front -> treeNode -> val);
            }
            else {
                traversal.push_back(levelValue);
                levelIndicator++;
                levelValue.clear();
                levelValue.push_back(front -> treeNode -> val);
            }

            TreeNodeWithLevel* childTreeNode = new TreeNodeWithLevel();
            if (front -> treeNode -> left != NULL) {
                childTreeNode -> treeNode = front -> treeNode -> left; 
                childTreeNode -> level = front -> level + 1;
                bfs_queue.push(childTreeNode);
            }

            if (front -> treeNode -> right != NULL) {
                childTreeNode -> treeNode = front -> treeNode -> right;
                childTreeNode -> level = front -> level + 1;
                bfs_queue.push(childTreeNode);
            }
        }
        return traversal;
    }
};