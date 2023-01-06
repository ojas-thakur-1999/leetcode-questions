#include<vector>
#include<string>
#include<iostream>
#include<map>

using namespace std;

class Solution {
private:
    int digit_sum(int n) {
        int sum = 0;
        while (n>0) {
            sum += (n%10)*(n%10);
            n /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        int fast = n, slow = n;
        do {
            slow = digit_sum(slow);
            fast = digit_sum(digit_sum(fast));
        } while (fast != slow);
        if (slow == 1) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Solution sol;

    int n = 1;
    printf("%d -> %d\n", n, sol.isHappy(n));
}