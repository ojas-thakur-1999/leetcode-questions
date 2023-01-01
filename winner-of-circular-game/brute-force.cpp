#include<iostream>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        int remaining_count = n;
        int eliminated[n];
        for (int i=0; i<n; i++) {
            eliminated[i] = 0;
        }
        int idx = 0;
        while (remaining_count > 1) {
            int j=0;
            while (j<k) {
                if (eliminated[idx] == 0) {
                    j += 1;
                    idx = (idx+1)%n;
                } else {
                    idx = (idx+1)%n;
                }
            }
            if (idx == 0) {
                eliminated[n-1] = 1;
            } else {
                eliminated[idx-1] = 1;    
            }
            remaining_count -= 1;
        }
        for (int i=0; i<n; i++) {
            if (eliminated[i] == 0) {
                return i+1;
            }
        }
        return 0;
    }
};

int main() {
    Solution sol;
    int n=5, k=2;
    printf("n -> %d\nk-> %d\nwinner-> %d\n\n", n, k, sol.findTheWinner(n, k));
}