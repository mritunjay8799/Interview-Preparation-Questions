Given a binary tree, return the inorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3
return [1,3,2].

Using recursion is not allowed.
___________________________________________________________________________________________________________________________________________________________________________________

vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int>v;
    stack<TreeNode*>st;
    while(1)
    {
        while(A)
        {
            st.push(A);
            A = A->left;
        }
        if(st.empty())
            break;
        A = st.top();
        st.pop();
        v.push_back(A->val);
        A = A->right;
    }
    return v;
}
