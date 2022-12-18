# Link to solutions
https://leetcode.com/problems/merge-intervals/submissions/861673958/?envType=study-plan&id=data-structure-ii

# Insights
Using a sorted list of intervals was the key here, once intervals are sorted based on their starting point, then we can merge or keep them separate in the final set as we read them. Inspiration for sorting should come from the point that finally we have to assemble the number line and read from 0 to top anyways, and hence, if we have a sorted array, then we can do this while reading each interval from the list.