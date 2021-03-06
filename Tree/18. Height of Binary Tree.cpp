Example 1:
Input:
      1
    /  \
   2    3
Output: 2

Example 2:
Input:
  2
   \
    1
   /
 3
Output: 3 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

=================================================================================================================================================================================

int height(Node* node)
{
   if (node == NULL)  
        return 0;  
    else
    {  
        /* compute the depth of each subtree */
        int lDepth = height(node->left);  
        int rDepth = height(node->right);  
      
        /* use the larger one */
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    } 

}
