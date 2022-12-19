# Link to solutions
https://leetcode.com/problems/daily-temperatures/submissions/861929469/

# Insights
Inspiration to use stack comes from the fact that in our search, if we come accross a smaller number, then we dismiss it and move to the next one. Now, instead of dismissing it, we will store it in a stack. If we come accross a number larger than the top of the stack, then we will pop the stack and mark its next largest as the current number.