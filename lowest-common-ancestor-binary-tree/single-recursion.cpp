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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left == nullptr) {
            return right;
        } else if (right == nullptr) {
            return left;
        } else {
            return root;
        }
    }
};

int main() {
    Solution sol;
    TreeNode n1(3), n2(7), n3(15), n4(9), n5(10);
    n2.left = &n1;
    n2.right = &n3;
    n3.left = &n4;
    n3.right = &n5;
    printf("p[%d], q[%d] => LCA[%d]\n\n", n1.val, n5.val, sol.lowestCommonAncestor(&n2, &n1, &n5)->val);
    // printf("[");
    // for (int i=0; i<ancestors_p.size(); i++) {
    //     printf("%d, ", ancestors_p[i]->val);
    // }
    // printf("]\n");
    // printf("[");
    // for (int i=0; i<ancestors_q.size(); i++) {
    //     printf("%d, ", ancestors_q[i]->val);
    // }
    // printf("]\n");
}