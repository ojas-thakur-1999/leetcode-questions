#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

class Node {
public:
    int frequency;
    char value;
    
    Node(char value, int frequency) {
        this->value = value;
        this->frequency = frequency;
    }
};

class Heap {
private:
    int size;
    int filledSize;
    Node* arr;

public:
    Heap(int size) {
        this->size = size;
        this->filledSize = 0;
        this->arr = (Node*)malloc((size+1) * sizeof(Node));
    }
    
    bool insert(char val, int freq) {
        if (this->filledSize == this->size) {
            return false;
        }
        this->filledSize++;
        int idx = this->filledSize;
        this->arr[idx].value = val;
        this->arr[idx].frequency = freq;
        Node temp = Node(val, freq);
        while (idx > 1) {
            if (this->arr[idx/2].frequency < temp.frequency) {
                this->arr[idx] = this->arr[idx/2];
                this->arr[idx/2] = temp;
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

    Node remove() {
        if (this->filledSize == 0) {
            return Node(0, 0);
        }
        Node top = this->arr[1];
        this->arr[1] = this->arr[this->filledSize];
        this->filledSize--;
        int idx = 1;
        while (idx < this->filledSize) {
            int left = 2*idx, right = 2*idx+1;
            if (left > this->filledSize) {
                break;
            } else if (right > this->filledSize) {
                if (this->arr[left].frequency > this->arr[idx].frequency) {
                    Node temp = this->arr[idx];
                    this->arr[idx] = this->arr[left];
                    this->arr[left] = temp;
                    idx = left;
                } else {
                    break;
                }
            } else {
                if (this->arr[idx].frequency >= this->arr[left].frequency && this->arr[idx].frequency >= this->arr[right].frequency) {
                    break;
                } else if (this->arr[left].frequency > this->arr[right].frequency) {
                    Node temp = this->arr[idx];
                    this->arr[idx] = this->arr[left];
                    this->arr[left] = temp;
                    idx = left;
                } else {
                    Node temp = this->arr[idx];
                    this->arr[idx] = this->arr[right];
                    this->arr[right] = temp;
                    idx = right;
                }
            }
        }
        return top;
    }

    void printHeap() {
        printf("[");
        for (int i=1; i<=this->filledSize; i++) {
            printf("%c, ", this->arr[i].frequency);
        }
        printf("]\n");
    }

};

class Solution {
public:
    string frequencySort(string s) {
        if (s.size() < 2) {
            return s;
        }
        sort(s.begin(), s.end(), greater<char>());
        Heap h(s.size());

        int repeat_count = 1;
        for (int i=1; i<s.size(); i++) {
            if (s[i] == s[i-1]) {
                repeat_count++;
            } else {
                h.insert(s[i-1], repeat_count);
                repeat_count = 1;
            }
        }
        h.insert(s[s.size()-1], repeat_count);

        string result;
        while (h.canRemove()) {
            Node temp = h.remove();
            for (int i=0; i<temp.frequency; i++) {
                result += temp.value;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    
    string s = "tree";
    printf("s -> %s\n", s.c_str());
    printf("sorted -> %s\n\n", sol.frequencySort(s).c_str());

}