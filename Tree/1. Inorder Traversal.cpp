Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [1,3,2]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1,2]
Output: [2,1]
Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

===================================================================================================================================================================================

class Solution {
public:
    void Inorder(TreeNode* root, vector<int>&v)
    {
        if(root == NULL)
            return;
        stack<TreeNode*>st;
        TreeNode* ptr = root;
        while(1)
        {
            while(ptr->left!=NULL)
            {
                st.push(ptr);
                ptr = ptr->left;
            }
            while(ptr->right == NULL)
            {
                v.push_back(ptr->val);
                if(st.empty())
                    return;
                ptr = st.top();
                st.pop();
            }
            v.push_back(ptr->val);
            ptr = ptr->right;
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
        Inorder(root,v);
        return v;
    }
};
