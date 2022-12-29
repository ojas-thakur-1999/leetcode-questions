#include<vector>
#include<map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        vector<ListNode*> found;
        while (head != nullptr) {
            if (inArray(found, head)) {
                return head;
            }
            found.push_back(head);
            head = head->next;
        }
        return nullptr;
    }
private:
    bool inArray(vector<ListNode*> &arr, ListNode* val) {
        for (int i=0; i<arr.size(); i++) {
            if (arr[i] == val) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    // [2,4,3,5,6,4 ---- 3]
    ListNode l1_1(2), l1_2(4), l1_3(3), l2_1(5), l2_2(6), l2_3(4);
    l1_1.next = &l1_2;
    l1_2.next = &l1_3;
    l1_3.next = &l2_1;
    l2_1.next = &l2_2;
    l2_2.next = &l2_3;
    l2_3.next = &l1_3;

    Solution sol;
    ListNode *cycle_start = sol.detectCycle(&l1_1);

    printf("%d\n", cycle_start->val);
}