Example Input
Input 1:

    3
   / \
  9  20
    /  \
   15   7
Input 2:

   1
  / \
 6   2
    /
   3


Example Output
Output 1:

 [15, 7, 9, 20, 3] 
Output 2:

 [3, 6, 2, 1]
 
___________________________________________________________________________________________________________________________________________________________________________________
  
vector<int> Solution::solve(TreeNode* A) {
    vector<int>ans;
    queue<TreeNode*>dq;
    dq.push(A);
    while(!dq.empty())
    {
        TreeNode* ptr = dq.front();
        dq.pop();
        if(ptr->right)
            dq.push(ptr->right);
        if(ptr->left)
            dq.push(ptr->left);
        ans.push_back(ptr->val);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
