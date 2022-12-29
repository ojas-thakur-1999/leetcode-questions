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
    ListNode* swapPairs(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode dummy(0, head);
        ListNode *prev = &dummy;
        while (true) {
            if (head == nullptr || head->next == nullptr) {
                break;
            }
            prev->next = head->next;
            head->next = head->next->next;
            prev->next->next = head;
            
            prev = head;
            head = head->next;
        }
        return dummy.next;
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
    ListNode l1(1), l2(6), l3(7), l4(2), l5(3), l6(9), l7(4), l8(5);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    l5.next = &l6;
    l6.next = &l7;
    l7.next = &l8;

    sol.printList(&l1);
    
    ListNode *result = sol.swapPairs(&l1);

    sol.printList(result);
}