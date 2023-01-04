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
        vector<TreeNode*> ancestors_p, ancestors_q;
        bool res = findAncestors(root, p, ancestors_p);
        res = findAncestors(root, q, ancestors_q);

        int min_len = min(ancestors_p.size(), ancestors_q.size());
        int found_idx = min_len+1;
        for (int i=0; i<min_len; i++) {
            if (ancestors_p[i]->val != ancestors_q[i]->val) {
                found_idx = i-1;
                break;
            }
        }
        return ancestors_p[found_idx];
    }
private:
    bool findAncestors(TreeNode* root, TreeNode* target, vector<TreeNode*> &ancestors) {
        if (root == nullptr) {
            return false;
        }
        if (root->val == target->val) {
            ancestors.push_back(root);
            return true;
        }
        
        ancestors.push_back(root);
        bool res = findAncestors(root->left, target, ancestors);
        if (res) {
            return true;
        }
        res = findAncestors(root->right, target, ancestors);
        if (res) {
            return true;
        }
        ancestors.pop_back();
        return false;
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