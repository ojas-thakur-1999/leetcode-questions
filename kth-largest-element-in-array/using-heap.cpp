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
    Heap(int size, vector<int> &init) {
        this->size = size;
        this->filledSize = init.size();
        this->arr = (int*)malloc((size+2) * sizeof(int));
        for (int i=1; i<=init.size(); i++) {
            this->arr[i] = init[i-1];
        }
        heapify();
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

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        Heap h = Heap(nums.size(), nums);
        int res = 0;
        for (int i=0; i<k; i++) {
            res = h.remove();
        }
        return res;
    }
};

int main() {

    vector<int> vec = {3,2,1,5,6,4};
    int k = 1;
    Solution sol;
    printf("%dth largest -> %d\n\n", k, sol.findKthLargest(vec, k));
}