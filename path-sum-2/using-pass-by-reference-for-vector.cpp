#include<vector>

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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        vector<int> nodes_so_far;
        recursive(root, result, nodes_so_far, targetSum);
        return result;
    }
private:
    void recursive(
        TreeNode *node,
        vector<vector<int>> &result,
        vector<int> &nodes_so_far,
        int target
    ) {
        if (node->right == nullptr && node->left == nullptr) {
            if (target-node->val == 0) {
                nodes_so_far.push_back(node->val);
                result.push_back(nodes_so_far);
                nodes_so_far.pop_back();
            }
            return;
        }

        nodes_so_far.push_back(node->val);
        if (node->left != nullptr) {
            recursive(node->left, result, nodes_so_far, target-node->val);
        }
        if (node->right != nullptr) {
            recursive(node->right, result, nodes_so_far, target-node->val);
        }
        nodes_so_far.pop_back();
    }
};