#include<vector>
#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int sum = 0;
        sum = carry + l1->val + l2->val;
        carry = sum / 10;
        ListNode* head = new ListNode(sum % 10);
        ListNode* prev_head = head;
        l1 = l1->next;
        l2 = l2->next;
        while (l1 != nullptr && l2 != nullptr) {
            sum = carry + l1->val + l2->val;
            carry = sum / 10;
            prev_head->next = new ListNode(sum % 10);
            l1 = l1->next;
            l2 = l2->next;
            prev_head = prev_head->next;
        }
        if (l1 == nullptr && l2 == nullptr) {
            if (carry > 0) {
                prev_head->next = new ListNode(carry);
            }
            return head;
        } else if (l1 != nullptr) {
            while (l1 != nullptr) {
                sum = carry + l1->val;
                carry = sum / 10;
                prev_head->next = new ListNode(sum % 10);
                l1 = l1->next;
                prev_head = prev_head->next;
            }
            if (carry > 0) {
                prev_head->next = new ListNode(carry);
            }
            return head;
        } else {
            while (l2 != nullptr) {
                sum = carry + l2->val;
                carry = sum / 10;
                prev_head->next = new ListNode(sum % 10);
                l2 = l2->next;
                prev_head = prev_head->next;
            }
            if (carry > 0) {
                prev_head->next = new ListNode(carry);
            }
            return head;
        }
    }
};

int main() {
    ListNode l1_1(2), l1_2(4), l1_3(3), l2_1(5), l2_2(6), l2_3(4);
    l1_1.next = &l1_2;
    l1_2.next = &l1_3;
    l1_3.next = nullptr;

    l2_1.next = &l2_2;
    l2_2.next = &l2_3;
    l2_3.next = nullptr;

    Solution sol;
    ListNode *result = sol.addTwoNumbers(&l1_1, &l2_1);
    
    ListNode *ptr = result;
    while (ptr != nullptr) {
        printf("%d, ", ptr->val);
        ptr = ptr->next;
    }
    printf("\n");
}