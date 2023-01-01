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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }

        if (root->val == key) {
            if (root->right == nullptr) {
                return root->left;
            }
            if (root->left == nullptr) {
                return root->right;
            }
            TreeNode *temp = root->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            temp->left = root->left;
            temp = root->right;
            delete(root);
            return temp;
        }

        list<TreeNode*> q;
        q.push_back(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop_front();
            if (node->left != nullptr && node->left->val == key) {
                if (node->left->right == nullptr) {
                    node->left = node->left->left;
                } else if (node->left->left == nullptr) {
                    node->left = node->left->right;
                } else {
                    TreeNode *temp = node->left->right;
                    while (temp->left != nullptr) {
                        temp = temp->left;
                    }
                    temp->left = node->left->left;
                    temp = node->left->right;
                    delete(node->left);
                    node->left = temp;
                }
            } else if (node->right != nullptr && node->right->val == key) {
                if (node->right->right == nullptr) {
                    node->right = node->right->left;
                } else if (node->right->left == nullptr) {
                    node->right = node->right->right;
                } else {
                    TreeNode *temp = node->right->right;
                    while (temp->left != nullptr) {
                        temp = temp->left;
                    }
                    temp->left = node->right->left;
                    temp = node->right->right;
                    delete(node->right);
                    node->right = temp;
                }
            } else {
                if (node->left != nullptr) {
                    q.push_back(node->left);
                }
                if (node->right != nullptr) {
                    q.push_back(node->right);
                }
            }
        }

        return root;
    }
};