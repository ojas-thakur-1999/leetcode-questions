#include<vector>
#include<string>
#include<iostream>

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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> in_order_traversal;
        usingRecursion(root, in_order_traversal);
        return in_order_traversal[k-1];
    }
private:
    void usingRecursion(TreeNode* root, vector<int> &in_order_traversal) {
        if (root == nullptr) {
            return;
        }
        usingRecursion(root->left, in_order_traversal);
        in_order_traversal.push_back(root->val);
        usingRecursion(root->right, in_order_traversal);
        return;
    }
};

int main() {}