#include<vector>
#include<string>
#include<iostream>
#include<cmath>

using namespace std;

class Point {
public:
    int x;
    int y;

    Point() {}
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

class Node {
public:
    float distance;
    Point value;
    
    Node(Point value, float distance) {
        this->value = value;
        this->distance = distance;
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
    
    bool insert(Point val, float dist) {
        if (this->filledSize == this->size) {
            return false;
        }
        this->filledSize++;
        int idx = this->filledSize;
        this->arr[idx].value = val;
        this->arr[idx].distance = dist;
        Node temp = Node(val, dist);
        while (idx > 1) {
            if (this->arr[idx/2].distance > temp.distance) {
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
            return Node(Point(0, 0), 0);
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
                if (this->arr[left].distance < this->arr[idx].distance) {
                    Node temp = this->arr[idx];
                    this->arr[idx] = this->arr[left];
                    this->arr[left] = temp;
                    idx = left;
                } else {
                    break;
                }
            } else {
                if (this->arr[idx].distance <= this->arr[left].distance && this->arr[idx].distance <= this->arr[right].distance) {
                    break;
                } else if (this->arr[left].distance < this->arr[right].distance) {
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
            printf("%f, ", this->arr[i].distance);
        }
        printf("]\n");
    }

};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        Heap h(points.size());
        for (int i=0; i<points.size(); i++) {
            h.insert(Point(points[i][0], points[i][1]), sqrt(pow(points[i][0], 2) + pow(points[i][1], 2)));
        }

        vector<vector<int>> result;
        for (int i=0; i<k; i++) {
            Node temp = h.remove();
            vector<int> point = {temp.value.x, temp.value.y};
            result.push_back(point);
        }
        return result;
    }
    
};

int main() {
    Solution sol;
    vector<vector<int>> points;
    vector<int> point;
    vector<vector<int>> res;
    
    // point.push_back(1);
    // point.push_back(3);
    // points.push_back(point);
    // point.clear();

    // point.push_back(-2);
    // point.push_back(2);
    // points.push_back(point);
    // point.clear();

    // res = sol.kClosest(points, 1);
    // for (int i=0; i<res.size(); i++) {
    //     printf("(%d, %d), ", res[i][0], res[i][1]);
    // }
    // printf("\n\n");

    point.push_back(3);
    point.push_back(3);
    points.push_back(point);
    point.clear();

    point.push_back(5);
    point.push_back(1);
    points.push_back(point);
    point.clear();

    point.push_back(-2);
    point.push_back(4);
    points.push_back(point);
    point.clear();

    res = sol.kClosest(points, 2);
    for (int i=0; i<res.size(); i++) {
        printf("(%d, %d), ", res[i][0], res[i][1]);
    }
    printf("\n\n");

}