Given a Binary Tree A containing N nodes.
You need to find the path from Root to a given node B.

NOTE
No two nodes in the tree have same data values.
You can assume that B is present in the tree A and a path always exists.


Problem Constraints
1 <= N <= 105
1 <= Data Values of Each Node <= N
1 <= B <= N

#Input Format
First Argument represents pointer to the root of binary tree A.
Second Argument is an integer B denoting the node number.

#Output Format
Return an one-dimensional array denoting the path from Root to the node B in order.

Example Input
Input 1:

 A =
           1
         /   \
        2     3
       / \   / \
      4   5 6   7 
B = 5

Example Output
Output 1:

 [1, 2, 5]
 
================================================================================================================================================================================

#METHOD - 1
-----------
  
void solve1(vector<int>&ans,TreeNode * root,int B)
 {
     if(root==NULL)
     return;
     if(root->val==B)
     {
         ans.push_back(root->val);
         return;
     }
     if(ans.size()==0)
     {
         solve1(ans,root->left,B);
     }
     if(ans.size()==0)
     {
         solve1(ans,root->right,B);
     }
     if(ans.size()>0)
     {
         ans.push_back(root->val);
         return;
     }
 }
vector<int> Solution::solve(TreeNode* A, int B) 
{
    vector<int>ans;
    solve1(ans,A,B);
    reverse(ans.begin(),ans.end());
    return ans;
}

===============================================================================================================================================================================
 
#METHOD -2
----------
  
bool solv(TreeNode* A,int B,vector<int>&ans)
{
    if(A==NULL)
    return false;
    if(A->val==B)
    {
        ans.pb(A->val);
        return true;
    }
    if(solv(A->left,B,ans) || solv(A->right,B,ans))
    {
        ans.pb(A->val);
        return true;
    }
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int>ans;
    solv(A,B,ans);
    reverse(ans.begin(),ans.end());
    return ans;
    
}
