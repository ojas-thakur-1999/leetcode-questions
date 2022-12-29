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
    ListNode* deleteDuplicates(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* dummy = new ListNode(head->val - 1);
        dummy->next = head;
        ListNode* prev = dummy;
        bool found_dupl = false;
        while (head->next != nullptr) {
            if (head->val == head->next->val) {
                head->next = head->next->next;
                found_dupl = true;
            } else {
                if (found_dupl) {
                    prev->next = head->next;
                    head = head->next;
                    found_dupl = false;
                } else {
                    prev = head;
                    head = head->next;
                }
            }
        }
        if (found_dupl) {
            prev->next = head->next;
        }

        return dummy->next;
    }

    void printList(ListNode *head) {
        while (head != nullptr) {
            printf("%d, ", head->val);
            head = head ->next;
        }
        printf("\n");
    }
};

int main() {
    Solution sol;
    ListNode l1(1), l2(1), l3(1), l4(2), l5(3), l6(3), l7(4), l8(5), l9(5);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    l5.next = &l6;
    l6.next = &l7;
    l7.next = &l8;
    l8.next = &l9;

    sol.printList(&l1);
    
    ListNode *result = sol.deleteDuplicates(&l1);

    sol.printList(result);
}