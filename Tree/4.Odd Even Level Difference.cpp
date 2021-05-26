Given a Binary Tree. Find the difference between the sum of node values at even levels and the sum of node values at the odd levels.

Example 1:
Input:
            1
          /   \
         2     3

Output: -4
Explanation:
sum at odd levels - sum at even levels
= (1)-(2+3) = 1-5 = -4

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)
  
===================================================================================================================================================================================
  
class Solution{
  public:
    int getLevelDiff(Node *root)
    {
        if(root==NULL)
            return 0;
       int odd_sum = 0;
       int even_sum = 0;
       queue<Node*>q;
       q.push(root);
       int level = 1;
       while(!q.empty())
       {
           int m = q.size();
           while(m--)
           {
               auto a = q.front();
               q.pop();
               if(level%2!=0)
                    odd_sum+=a->data;
               else
                    even_sum+= a->data;
                if(a->left!=NULL)
                    q.push(a->left);
                if(a->right!=NULL)
                    q.push(a->right);
           }
            level++;
       }
       return odd_sum-even_sum;
    }
};
