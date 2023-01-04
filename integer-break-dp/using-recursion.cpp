#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        return usingRecursion(n, 0);
    }
private:
    int usingRecursion(int n, int level) {
        if (n==1) {
            return 1;
        }
        int max_prod = 0;
        for (int i=1; i<n; i++) {
            max_prod = max(max_prod, i*usingRecursion(n-i, level+1));
        }
        if (level > 0 && max_prod < n) {
            max_prod = n;
        }
        return max_prod;
    }
};

int main() {
    Solution sol;
    int n = 30;
    printf("n = [%d], ans = [%d]\n\n", n, sol.integerBreak(n));
}