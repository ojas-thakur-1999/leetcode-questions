# Link to solutions
https://leetcode.com/problems/minimum-size-subarray-sum/submissions/864212649/?envType=study-plan&id=algorithm-ii

# Insights
using s sliding window approach by keeping start and end pointers to vary length of sliding window. keep increasing end till we reach the sum >= target. then keep increasing start, till sum >= target. after that increase end.