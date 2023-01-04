struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include<vector>
#include<string>
#include<iostream>

using namespace std;

class BSTIterator {
private:
    vector<int> nodes;
    int size;
    int curr_idx;

    void recursive(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        recursive(node->left);
        this->nodes.push_back(node->val);
        recursive(node->right);
    }

public:
    BSTIterator(TreeNode* root) {
        recursive(root);
        this->size = this->nodes.size();
        this->curr_idx = -1;
    }
    
    int next() {
        this->curr_idx++;
        return this->nodes[this->curr_idx];
    }
    
    bool hasNext() {
        return this->curr_idx < this->size-1;
    }
};

int main() {
    TreeNode n1(3), n2(7), n3(15), n4(9), n5(10);
    n2.left = &n1;
    n2.right = &n3;
    n3.left = &n4;
    n3.right = &n5;

    BSTIterator iter = BSTIterator(&n2);
    printf("%d\n", iter.next());
    printf("%d\n", iter.next());
    if (iter.hasNext()) {
        printf("has next\n");
    } else {
        printf("does not have next\n");
    }
    printf("%d\n", iter.next());
    if (iter.hasNext()) {
        printf("has next\n");
    } else {
        printf("does not have next\n");
    }
    printf("%d\n", iter.next());
    if (iter.hasNext()) {
        printf("has next\n");
    } else {
        printf("does not have next\n");
    }
    printf("%d\n", iter.next());
    if (iter.hasNext()) {
        printf("has next\n");
    } else {
        printf("does not have next\n");
    }
}