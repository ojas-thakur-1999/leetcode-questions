#include<vector>
#include<string>
#include<iostream>
using namespace std;

class MyListNode {
public:
    int val;
    MyListNode *next;
    MyListNode *prev;
    MyListNode(int val=0, MyListNode *next=nullptr, MyListNode *prev=nullptr) {
        this->val = val;
        this->next = next;
        this->prev = prev;
    }
};

class MyLinkedList {
private:
    MyListNode *head;
    MyListNode *tail;
    int size;
public:
    MyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= this->size) {
            return -1;
        }
        MyListNode *ptr = this->head;
        for (int i=1; i<=index; i++) {
            ptr = ptr->next;
        }
        return ptr->val;
    }
    
    void addAtHead(int val) {
        if (this->size == 0) {
            this->head = new MyListNode(val, nullptr, nullptr);
            this->size += 1;
            this->tail = this->head;
        } else {
            MyListNode *temp = new MyListNode(val, this->head, nullptr);
            this->head->prev = temp;
            this->size += 1;
            this->head = temp;
        }
    }
    
    void addAtTail(int val) {
        if (this->size == 0) {
            this->tail = new MyListNode(val, nullptr, nullptr);
            this->head = this->tail;
            this->size += 1;
        } else {
            this->tail->next = new MyListNode(val, nullptr, this->tail);
            this->size += 1;
            this->tail = this->tail->next;
        }
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > this->size) {
            return;
        } else if (this->size == 0) {
            this->head = new MyListNode(val, nullptr, nullptr);
            this->size += 1;
            this->tail = this->head;
        }else if (index == 0) {
            MyListNode *temp = new MyListNode(val, this->head, nullptr);
            this->head->prev = temp;
            this->head = temp;
            this->size += 1;
        } else if (index == this->size) {
            MyListNode *temp = new MyListNode(val, nullptr, this->tail);
            this->tail->next = temp;
            this->tail = temp;
            this->size += 1;
        } else {
            MyListNode *ptr = this->head;
            for (int i=1; i<index; i++) {
                ptr = ptr->next;
            }
            MyListNode *temp = new MyListNode(val, ptr->next, ptr);
            ptr->next->prev = temp;
            ptr->next = temp;
            this->size += 1;
        }
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= this->size) {
            return;
        } else if (this->size == 1) {
            delete(this->head);
            this->head = nullptr;
            this->tail = nullptr;
            this->size = 0;
        } else if (index == 0) {
            MyListNode *temp = this->head;
            this->head = this->head->next;
            this->head->prev = nullptr;
            this->size -= 1;
            delete(temp);
        } else if (index == this->size - 1) {
            MyListNode *temp = this->tail;
            this->tail = this->tail->prev;
            this->tail->next = nullptr;
            this->size -= 1;
            delete(temp);
        } else {
            MyListNode *ptr = this->head;
            for (int i=1; i<=index; i++) {
                ptr = ptr->next;
            }
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            delete(ptr);
            this->size -= 1;
        }
    }
};

int main() {
    MyLinkedList sol = MyLinkedList();
    // sol.addAtHead(7);
    // sol.addAtHead(2);
    // sol.addAtHead(1);
    sol.addAtIndex(0,10);
    sol.addAtIndex(0,20);
    sol.addAtIndex(1,30);
    
    printf("list[%d] - %d\n", 0, sol.get(0));
    // printf("list[%d] - %d\n", 1, sol.get(1));
    // printf("list[%d] - %d\n", 2, sol.get(2));
    // printf("list[%d] - %d\n", 3, sol.get(3));
    
    // sol.deleteAtIndex(2);
    // sol.addAtHead(6);
    // sol.addAtTail(4);
    // printf("list[%d] - %d\n", 4, sol.get(4));
    // sol.addAtHead(4);
    // sol.addAtIndex(5,0);
    // sol.addAtHead(6);
}