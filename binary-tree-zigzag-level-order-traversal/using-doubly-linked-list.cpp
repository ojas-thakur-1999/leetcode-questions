#include<vector>
#include<iostream>
#include<list>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        vector<int> current_level;
        list<TreeNode*> queue;
        queue.push_back(root);
        bool direction = true;

        while (!queue.empty()) {
            int level_size = queue.size();
            vector<int> current_level;
            if (direction) {
                for (int i=0; i<level_size; i++) {
                    TreeNode *node = queue.front();
                    queue.pop_front();
                    current_level.push_back(node->val);
                    if (node->left != nullptr) {
                        queue.push_back(node->left);
                    }
                    if (node->right != nullptr) {
                        queue.push_back(node->right);
                    }
                }
                direction = false;
            } else {
                for (int i=0; i<level_size; i++) {
                    TreeNode *node = queue.back();
                    queue.pop_back();
                    current_level.push_back(node->val);
                    if (node->right != nullptr) {
                        queue.push_front(node->right);
                    }
                    if (node->left != nullptr) {
                        queue.push_front(node->left);
                    }
                }
                direction = true;
            }
            result.push_back(current_level);
        }

        return result;
    }
};