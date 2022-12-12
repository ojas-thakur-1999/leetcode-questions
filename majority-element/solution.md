# Link to solutions
https://leetcode.com/problems/majority-element/submissions/

# Insights
Simple solution using python dictionary, iterating over the loop twice. Another approach can be to sort the array first and then, since the majority element must occur more than n2 times, it must also occur at the middle of the array. Hence return the middle element.