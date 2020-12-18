Given a binary tree of size N, find its reverse level order traversal. ie- the traversal must begin from the last level.

Example 1:
Input :
        1
      /   \
     3     2

Output: 3 2 1
Explanation:
Traversing level 1 : 3 2
Traversing level 0 : 1

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

==================================================================================================================================================================================
PUSH RIGHT CHILD FIRST AND THEN LEFT, AND FINALLY REVERSE THE WHOLE VECTOR.

vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<int>res;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        auto a = q.front();
        q.pop();
        res.push_back(a->data);
        if(a->right!=NULL)
            q.push(a->right);
        if(a->left!=NULL)
            q.push(a->left);
    }
    reverse(res.begin(),res.end());
    return res;
}

METHOD 2 - RECURSIVELY
-----------------------
