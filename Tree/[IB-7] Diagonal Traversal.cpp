Example Input
Input 1:

            1
          /   \
         4      2
        / \      \
       8   5      3
          / \    /
         9   7  6
Input 2:

             11
          /     \
         20      12
        / \       \
       1   15      13
          /  \     /
         2    17  16
          \   /
          22 34


Example Output
Output 1:

 [1, 2, 3, 4, 5, 7, 6, 8, 9]
Output 2:

 [11, 12, 13, 20, 15, 17, 16, 1, 2, 22, 34]
 
___________________________________________________________________________________________________________________________________________________________________________________
  
void diagonalPrintUtil(TreeNode* root, int d, map<int, vector<int>> &diagonalPrint) 
{ 
    if (!root) 
        return; 
    diagonalPrint[d].push_back(root->val); 
  
    diagonalPrintUtil(root->left, d + 1, diagonalPrint); 
  
    diagonalPrintUtil(root->right, d, diagonalPrint); 
} 
vector<int> Solution::solve(TreeNode* A) {
    map<int, vector<int> > diagonalPrint; 
    vector<int>vec;
    diagonalPrintUtil(A, 0, diagonalPrint); 
  
    for (auto it = diagonalPrint.begin(); it != diagonalPrint.end(); ++it) 
    { 
        for (auto itr = it->second.begin();itr != it->second.end(); ++itr) 
            vec.push_back(*itr);
    } 
    
    return vec;
}
_________________________________________________________________________________________________________________________________________________________________________________
  
vector<int> Solution::solve(TreeNode* root) {
    if (!root) return {};

    vector<int> ans;

    deque<TreeNode*> dq;
    dq.push_front(root);

    while (!dq.empty()) {
        TreeNode* node = dq.front();
        dq.pop_front();

        ans.push_back(node->val);

        if (node->left) {
            dq.push_back(node->left);
        }

        if (node->right) {
            dq.push_front(node->right);
        }

        delete node;
    }

    return ans;
}
