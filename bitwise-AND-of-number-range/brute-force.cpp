#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m == 0){
            return 0;
        }
        int moveFactor = 1;
        while(m != n){
            m >>= 1;
            n >>= 1;
            moveFactor <<= 1;
        }
        return m * moveFactor;
    }
};

int main() {
    Solution sol;

    int left = 1, right = 2147483647;

    printf("left[%d], right[%d] => answer[%d]\n\n", left, right, sol.rangeBitwiseAnd(left, right));
}