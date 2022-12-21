# Link to solutions
https://leetcode.com/problems/container-with-most-water/submissions/?envType=study-plan&id=algorithm-ii

# Insights
* Using 2 iterators, one from start and one from end. Storing max_area at each step and incrementing the iterator with smaller height.
* For an optimized solution, keep on incrementing the iterator with smaller height as long as its height is <= current min_height