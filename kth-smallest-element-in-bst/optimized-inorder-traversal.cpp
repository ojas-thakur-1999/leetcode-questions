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
        return usingRecursion(root, k);
    }
private:
    int usingRecursion(TreeNode* root, int &k) {
        int x = -1;
        if (root == nullptr) {
            return -1;
        }

        if (root->left != nullptr) {
            x = usingRecursion(root->left, k);
        }
        if (x >= 0) {
            return x;
        }

        k--;
        if (k==0) {
            return root->val;
        }

        if (root->right) {
            x = usingRecursion(root->right, k);
        }
        if (x >= 0) {
            return x;
        }

        return -1;
    }
};

int main() {}