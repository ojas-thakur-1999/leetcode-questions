#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode *ptr, *prevA, *prevB;

        // find len of A
        ptr = headA;
        lenA += 1;
        prevA = ptr;
        ptr = ptr->next;
        while (ptr != nullptr) {
            lenA += 1;
            prevA = ptr;
            ptr = ptr->next;
        }

        // find len of B
        ptr = headB;
        lenB += 1;
        prevB = ptr;
        ptr = ptr->next;
        while (ptr != nullptr) {
            lenB += 1;
            prevB = ptr;
            ptr = ptr->next;
        }

        // if tails are not the same, then don't intersect
        if (prevA != prevB) {
            return nullptr;
        }

        // make lengths equal by skipping elements from longer list
        if (lenA > lenB) {
            for (int i=0; i<lenA-lenB; i++) {
                headA = headA->next;
            }
        } else if (lenB > lenA) {
            for (int i=0; i<lenB-lenA; i++) {
                headB = headB->next;
            }
        }

        // now since both have equal length, check one element at a time
        while (headA != nullptr && headB != nullptr) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }

        // if not found till end, return null
        return nullptr;
    }
};

int main() {
    Solution sol;

    ListNode common1(1), common2(8);
    common1.next = &common2;

    ListNode l1_1(4), l1_2(2), l1_3(3);
    l1_1.next = &l1_2;
    l1_2.next = &l1_3;
    l1_3.next = &common1;
    
    ListNode l2_1(5);
    l2_1.next = &common1;

    ListNode* res = sol.getIntersectionNode(&l1_1, &l2_1);
    if (res != nullptr) {
        printf("%d\n", res->val);
    } else {
        printf("NULL\n");
    }
}