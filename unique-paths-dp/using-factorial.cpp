#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int n, int m) {
        if (m<=0 || n<=0) {
            return -1;
        }
        return factorial(m+n-2)/(factorial(m-1)*factorial(n-1));
    }
private:
    int factorial(int n) {
        if (n==0) {
            return 1;
        }
        int prev = 1;
        int curr = prev;
        for (int i=1; i<=n; i++) {
            curr = i * prev;
            prev = curr;
        }
        return curr;
    }
};

int main() {
    Solution sol;
    printf("%d\n", sol.uniquePaths(3,7));
}