Given a binary tree, find its level order traversal.
Level order traversal of a tree is breadth-first traversal for the tree.

Example 1:

Input:
    1
  /   \ 
 3     2
Output:1 3 2

==================================================================================================================================================================================

vector<int> levelOrder(Node* node)
{
  vector<int>v;
  queue<Node*>q;
  q.push(node);
  while(!q.empty())
  {
      auto d = q.front();
      q.pop();
      v.push_back(d->data);
      if(d->left)
        q.push(d->left);
      if(d->right)
        q.push(d->right);
  }
  return v;
}
