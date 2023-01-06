#include<vector>
#include<string>
#include<iostream>
#include<time.h>

using namespace std;

class Solution {
private:
    vector<int> origArray;

public:
    Solution(vector<int>& nums) {
        this->origArray = nums;
        srand(time(0));
    }
    
    vector<int> reset() {
        return this->origArray;
    }
    
    vector<int> shuffle() {
        vector<int> shuffled(this->origArray);
        for (int i=0; i<shuffled.size(); i++) {
            int j = rand()%(i+1);
            int temp = shuffled[i];
            shuffled[i] = shuffled[j];
            shuffled[j] = temp;
        }
        return shuffled;
    }
};

int main() {
    vector<int> input = {1,2,3,4,5,6,7};
    Solution sol(input);
    vector<int> res = sol.shuffle();
    for (int i=0; i<res.size(); i++) {
        printf("%d, ", res[i]);
    }
    printf("\n\n");
}