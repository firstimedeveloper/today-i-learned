## Tips for leetcode problems
I was solving the [validate-binary-search-tree](https://leetcode.com/problems/validate-binary-search-tree/) problem using python.
In the problem, you had to go down the bst nodes to check whether the bst is valid or not. The method I used is a recursive function that checks the left and right nodes recursively, while keeping track of the upper and lower bounds of the lower nodes.
The problem I encountered arose from the way I kept track of the valid flag. I kept a boolean variable at the top of the function and as my recursive function worked its way down the bst, the boolean variable outside the scope would be changed. 
However I was not aware of how scope of immutable variables were handled in python.

The solution was to change the boolean value to an array of a Boolean value.

```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        
        ret = [True]
        def recur(node: Optional[TreeNode], lower, upper):
            if not node:
                return
            if node.val >= upper or node.val <= lower:
                ret[0] = False
                return
            if node.left:
                if node.left.val >= node.val:
                    ret[0] = False
                    return
                recur(node.left, lower, node.val)
            if node.right:
                if node.right.val <= node.val:
                    print("\tright", node.right.val, node.val)
                    ret[0] = False
                    return
                recur(node.right, node.val, upper)
    
        recur(root, float("-inf"), float("inf"))
        return ret[0]
```
