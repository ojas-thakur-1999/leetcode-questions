# Link to solutions
https://leetcode.com/problems/search-a-2d-matrix-ii/submissions/862607150/

# Insights
* First tried a solution using recursion, by checking in the first row and column, and then reducing the size of matrix by one row and one column from top and left. Also, only taking till that row till where the row header is smaller than target, same with column.
* Another approach is to start from the bottom left corner. From here, if the number is greater than target, then move up one row, because all numbers in this row will be greater than current number. Also, if the number is lesser than target, then move one one column right, because all numbers above this will be smaller than current number.