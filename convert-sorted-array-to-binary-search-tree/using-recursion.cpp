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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) {
            return nullptr;
        }
        return usingRecursion(nums, 0, nums.size()-1);
    }
private:
    TreeNode* usingRecursion(vector<int> &nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int mid = (start+end)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = usingRecursion(nums, start, mid-1);
        root->right = usingRecursion(nums, mid+1, end);
        return root;
    }
};