Example Input
Input 1:

        1
      /   \
     2    3
    / \  / \
   4   5 6  7
  /
 8 
Input 2:

    1
   /  \
  2    3
   \
    4
     \
      5

Example Output
Output 1:

 [1, 3, 7, 8]
Output 2:

 [1, 3, 4, 5]
_________________________________________________________________________________________________________________________________________________________________________________

#Iterative
-----------

vector<int> Solution::solve(TreeNode* A) {
    vector<int>ans;
    queue<TreeNode*>q;
    q.push(A);
    while(!q.empty())
    {
           int n = q.size();
           int a;
           while(n--)
           {
               TreeNode*ptr= q.front();
               q.pop();
               a = ptr->val;
               if(ptr->left)
                    q.push(ptr->left);
               if(ptr->right)
                    q.push(ptr->right);
           }
           ans.push_back(a);
    }
    return ans;
}
