Given a binary tree A with N nodes.
You have to remove all the half nodes and return the final binary tree.

NOTE:
Half nodes are nodes which have only one child.
Leaves should not be touched as they have both children as NULL.

Problem Constraints
1 <= N <= 105
Input Format
First and only argument is an pointer to the root of binary tree A.

Output Format
Return a pointer to the root of the new binary tree.

Example Input
Input 1:

           1
         /   \
        2     3
       / 
      4

Example Output
Output 1:

           1
         /   \
        4     3

===============================================================================================================================================================================

TreeNode* Solution::solve(TreeNode* A) {
    if(A->left == NULL && A->right == NULL)return A;
    if(A->left == NULL)
        return solve(A->right);
    if(A->right == NULL)
        return solve(A->left);
    A->left = solve(A->left);
    A->right = solve(A->right);
    return A;
    
}
