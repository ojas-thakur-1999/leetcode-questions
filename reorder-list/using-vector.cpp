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

void printList(ListNode *head) {
    while (head != nullptr) {
        printf("%d, ", head->val);
        head = head->next;
    }
    printf("\n");
}

class Solution {
    public:
    void reorderList(ListNode *head) {
        if (head == nullptr) {
            return;
        }
        vector<ListNode*> node_pointers;
        ListNode *ptr = head;
        while (ptr != nullptr) {
            node_pointers.push_back(ptr);
            ptr = ptr->next;
        }
        int len = node_pointers.size();

        ListNode *dummy = new ListNode(0);
        ListNode *prev = dummy;
        dummy->next = head;
        for (int i=0; i<len/2; i++) {
            prev->next = node_pointers[i];
            prev->next->next = node_pointers[len-1-i];
            prev = prev->next->next;
        }
        if (len % 2 == 0) {
            prev->next = nullptr;
        } else {
            prev->next = node_pointers[len/2];
            prev->next->next = nullptr;
        }
    }
};

int main() {
    Solution sol;

    // ListNode l1_1(1), l1_2(2), l1_3(3), l1_4(4);
    // l1_1.next = &l1_2;
    // l1_2.next = &l1_3;
    // l1_3.next = &l1_4;
    // printList(&l1_1);
    // sol.reorderList(&l1_1);
    // printList(&l1_1);
    
    ListNode l2_1(1), l2_2(2), l2_3(3);
    l2_1.next = &l2_2;
    l2_2.next = &l2_3;
    printList(&l2_1);
    sol.reorderList(&l2_1);
    printList(&l2_1);

}