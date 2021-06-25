Given a binary search tree, write a function to find the kth smallest element in the tree.

Example :
Input : 
  2
 / \
1   3

and k = 2
Return : 2
As 2 is the second smallest element in the tree.
=================================================================================================================================================================================

USING EXTRA SPACE (METHOD 1)
----------------------------
   void solve(TreeNode* A, vector<int>&v)
 {
     if(A == NULL)
        return;
     solve(A->left,v);
     v.push_back(A->val);
     solve(A->right,v);
 }
 
int Solution::kthsmallest(TreeNode* A, int B) {
    if(A == NULL)
        return 0;
    vector<int>v;
    solve(A,v);
    return v[B-1];
}

================================================================================================================================================================================
   
 WITHOUT EXTRA SPACE (METHOD 2)
 -------------------------------

void traverse(TreeNode *A, int &B, int &C) {
    if (A == nullptr) {
        return;
    }
    traverse(A->left, B, C);
    B--;
    if (B == 0) {
        C = A->val;
        return;
    }
    traverse(A->right, B, C);
}

int Solution::kthsmallest(TreeNode *A, int B) {
    if (A == nullptr) {
        throw invalid_argument("empty tree");
    }
    int C;
    traverse(A, B, C);
    return C;
}
