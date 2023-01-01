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
        bool left_to_right = true;

        while (!queue.empty()) {
            int level_size = queue.size();
            vector<int> current_level(level_size);
            for (int i=0; i<level_size; i++) {
                TreeNode *node = queue.front();
                queue.pop_front();
                int idx = left_to_right ? i : level_size-1-i;
                current_level[idx] = node->val;
                if (node->left != nullptr) {
                    queue.push_back(node->left);
                }
                if (node->right != nullptr) {
                    queue.push_back(node->right);
                }
            }
            left_to_right = !left_to_right;
            result.push_back(current_level);
        }

        return result;
    }
};