# Link to solutions
https://leetcode.com/problems/find-peak-element/submissions/863075800/?envType=study-plan&id=algorithm-ii

# Insights
* Any peak will be a local maximum. We can just find the global maximum since it will also be a local maximum.
* Even if the array is not sorted, we can go via a binary search approach, by firt checking if the mid element is a peak. If not, then check the left element, if it is greater than mid, then search in left sub-array. Similarly for the right element.
* Above approach works because in both cases, we are always moving up the slope. So if it is monotonic and we approach the end, then too it will be a maxima.
* Instead of having one big if condition, if there are if-else blocks, then it works faster.