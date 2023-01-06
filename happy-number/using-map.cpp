#include<vector>
#include<string>
#include<iostream>
#include<map>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        map<int, bool> m;
        return isHappyRecursive(n, m);
    }

    bool isHappyRecursive(int n, map<int, bool> &m) {
        if (m.count(n) == 0) {
            m[n] = true;
            int sum = 0;
            while (n > 0) {
                int digit = n % 10;
                sum += digit*digit;
                n /= 10;
            }
            if (sum == 1) {
                return true;
            }
            return isHappyRecursive(sum, m);
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