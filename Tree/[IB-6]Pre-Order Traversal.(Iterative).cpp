Given a binary tree, return the preorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3
return [1,2,3].

Using recursion is not allowed.
___________________________________________________________________________________________________________________________________________________________________________________

vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int>v;
    stack<TreeNode*>st;
    st.push(A);
    while(!st.empty())
    {
        TreeNode* ptr = st.top();
        st.pop();
        v.push_back(ptr->val);
        if(ptr->right)
            st.push(ptr->right);
        if(ptr->left)
            st.push(ptr->left);
    }
    return v;
}
