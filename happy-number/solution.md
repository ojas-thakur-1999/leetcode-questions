# Link to solutions
https://leetcode.com/problems/happy-number/submissions/872520355/?envType=study-plan&id=algorithm-ii

# Insights
* one solutions is to keep a map with all numbers previously spotted and use recursion
* this is similar to finding a cycle in a linked list (floyds cycle algo)
* floyds-algo is used to find cycle in linked list. this works by having a slow pointer and a fast pointer. if we imagine that there is a loop somewhere in the linked list, the slow pointer will reach the last node slowly, till that time, the fast pointer would already have entered the loop and went around the cycle multiple times.