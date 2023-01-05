#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Heap {
private:
    int size;
    int filledSize;
    int* arr;

    void heapify() {
        for (int i=this->filledSize/2; i>0; i--) {
            heapifyRecursive(i);
        }
    }

    void heapifyRecursive(int i) {
        int left = 2*i;
        int right = 2*i + 1;
        
        int largest = i;
        if (left <= this->filledSize && this->arr[left] > this->arr[largest]) {
            largest = left;
        }
        if (right <= this->filledSize && this->arr[right] > this->arr[largest]) {
            largest = right;
        }
        if (largest != i) {
            int temp = this->arr[i];
            this->arr[i] = this->arr[largest];
            this->arr[largest] = temp;
            heapifyRecursive(largest);
        }
    }

public:
    Heap(int size) {
        this->size = size;
        this->filledSize = 0;
        this->arr = (int*)malloc((size+1) * sizeof(int));
    }

    Heap(int size, vector<int> &init) {
        this->size = size;
        this->filledSize = init.size();
        this->arr = (int*)malloc((size+2) * sizeof(int));
        for (int i=1; i<=init.size(); i++) {
            this->arr[i] = init[i-1];
        }
        heapify();
    }

    bool insert(int val) {
        if (this->filledSize == this->size) {
            return false;
        }
        this->filledSize++;
        int idx = this->filledSize;
        this->arr[idx] = val;
        while (idx > 1) {
            if (this->arr[idx/2] < val) {
                this->arr[idx] = this->arr[idx/2];
                this->arr[idx/2] = val;
                idx = idx/2;
            } else {
                break;
            }
        }
        return true;
    }

    bool canRemove() {
        return this->filledSize > 0;
    }
    
    void printHeap() {
        printf("[");
        for (int i=1; i<=this->filledSize; i++) {
            printf("%d, ", this->arr[i]);
        }
        printf("]\n");
    }

    int remove() {
        if (this->filledSize == 0) {
            return 0;
        }
        int top = this->arr[1];
        this->arr[1] = this->arr[this->filledSize];
        this->filledSize--;
        int idx = 1;
        while (idx < this->filledSize) {
            int left = 2*idx, right = 2*idx+1;
            if (left > this->filledSize) {
                break;
            } else if (right > this->filledSize) {
                if (this->arr[left] > this->arr[idx]) {
                    int temp = this->arr[idx];
                    this->arr[idx] = this->arr[left];
                    this->arr[left] = temp;
                    idx = left;
                } else {
                    break;
                }
            } else {
                if (this->arr[idx] >= this->arr[left] && this->arr[idx] >= this->arr[right]) {
                    break;
                } else if (this->arr[left] > this->arr[right]) {
                    int temp = this->arr[idx];
                    this->arr[idx] = this->arr[left];
                    this->arr[left] = temp;
                    idx = left;
                } else {
                    int temp = this->arr[idx];
                    this->arr[idx] = this->arr[right];
                    this->arr[right] = temp;
                    idx = right;
                }
            }
        }
        return top;
    }
};

int main() {

    vector<int> vec = {3,2,1,5,6,4};
    Heap h2 = Heap(vec.size(), vec);
    h2.printHeap();

    // vector<int> init;
    // init.push_back(4);
    // init.push_back(7);
    // init.push_back(10);
    // init.push_back(3);
    // init.push_back(2);
    // init.push_back(5);
    // init.push_back(1);
    // Heap h1 = Heap(10, init);
    // h1.printHeap();
    // printf("largest -> %d\n", h1.remove());
    // printf("largest -> %d\n", h1.remove());
    // printf("largest -> %d\n", h1.remove());
    // printf("largest -> %d\n", h1.remove());
    // printf("largest -> %d\n", h1.remove());

    // Heap h = Heap(10);
    // if (h.insert(4)) {
    //     printf("successfully inserted\n");
    // } else {
    //     printf("failed to insert\n");
    // }

    // if (h.insert(7)) {
    //     printf("successfully inserted\n");
    // } else {
    //     printf("failed to insert\n");
    // }

    // if (h.insert(10)) {
    //     printf("successfully inserted\n");
    // } else {
    //     printf("failed to insert\n");
    // }

    // if (h.insert(3)) {
    //     printf("successfully inserted\n");
    // } else {
    //     printf("failed to insert\n");
    // }

    // if (h.insert(2)) {
    //     printf("successfully inserted\n");
    // } else {
    //     printf("failed to insert\n");
    // }

    // if (h.insert(5)) {
    //     printf("successfully inserted\n");
    // } else {
    //     printf("failed to insert\n");
    // }

    // if (h.insert(1)) {
    //     printf("successfully inserted\n");
    // } else {
    //     printf("failed to insert\n");
    // }

    // // h.printHeap();

    // if (h.canRemove()) {
    //     printf("top element -> %d\n", h.remove());
    // } else {
    //     printf("failed to remove\n");
    // }

    // if (h.canRemove()) {
    //     printf("top element -> %d\n", h.remove());
    // } else {
    //     printf("failed to remove\n");
    // }

    // if (h.canRemove()) {
    //     printf("top element -> %d\n", h.remove());
    // } else {
    //     printf("failed to remove\n");
    // }

    // if (h.canRemove()) {
    //     printf("top element -> %d\n", h.remove());
    // } else {
    //     printf("failed to remove\n");
    // }

    // if (h.canRemove()) {
    //     printf("top element -> %d\n", h.remove());
    // } else {
    //     printf("failed to remove\n");
    // }

}