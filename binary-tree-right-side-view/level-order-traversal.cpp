#include<iostream>
#include<vector>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        list<TreeNode*> q;
        q.push_back(root);
        while (!q.empty()) {
            int curr_level_size = q.size();
            int curr_level_view = 0;
            for (int i=0; i<curr_level_size; i++) {
                TreeNode *node = q.front();
                q.pop_front();
                curr_level_view = node->val;
                if (node->left) {
                    q.push_back(node->left);
                }
                if (node->right) {
                    q.push_back(node->right);
                }
            }
            result.push_back(curr_level_view);
        }

        return result;
    }
};