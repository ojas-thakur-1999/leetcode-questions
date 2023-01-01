#include<vector>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return usingRecursion(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
private:
    TreeNode* usingRecursion(
        vector<int> &preorder,
        int pre_order_start,
        int pre_order_end,
        vector<int> &inorder,
        int in_order_start,
        int in_order_end
    ) {
        printf("in_order_start[%d], in_order_end[%d], pre_order_start[%d], pre_order_end[%d]\n", in_order_start, in_order_end, pre_order_start, pre_order_end);
        if (in_order_start > in_order_end || pre_order_start > pre_order_end) {
            return nullptr;
        }

        int root = preorder[pre_order_start];
        int root_index = in_order_start;
        for (; root_index<=in_order_end; root_index++) {
            if (root == inorder[root_index]) {
                break;
            }
        }
        TreeNode *root_node = new TreeNode(root);
        root_node->left = usingRecursion(
            preorder,
            pre_order_start+1,
            pre_order_start+(root_index-in_order_start),
            inorder,
            in_order_start,
            root_index-1
        );
        root_node->right = usingRecursion(
            preorder,
            pre_order_start+(root_index-in_order_start)+1,
            pre_order_end,
            inorder,
            root_index+1,
            in_order_end
        );
        
        return root_node;
    }
};


int main() {
    Solution sol;

    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};

    TreeNode *result = sol.buildTree(preorder, inorder);
}