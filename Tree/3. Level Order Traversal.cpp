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
=================================================================================================================================================================================
 
 When a 2-D vector has to return - After every level, put a NULL and use it as separator for different levels.
 --------------------------------
    
    class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
       vector<vector<int> >res;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while(q.size()!=1)
        {
            vector<int>temp;
            while(q.front()!=NULL)
            {
                auto a = q.front();
                temp.push_back(a->val);
                q.pop();
                if(a->left!=NULL)
                    q.push(a->left);
                if(a->right!=NULL)
                    q.push(a->right);
            }
            q.push(NULL);
            q.pop();
            res.push_back(temp);
        }
        return res;
    }
};
 
-----------------------------------------------------------------OR YOU CAN USE SIZE OF QUEUE AS SEPARATOR --------------------------------------------------------------------

 if(root==NULL)
            return {};
        vector<vector<int> >res;
        queue<TreeNode*>q;
        vector<int>v;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            while(n)
            {
                TreeNode*ptr = q.front();
                q.pop();
                v.push_back(ptr->val);
                if(ptr->left)
                    q.push(ptr->left);
                if(ptr->right)
                    q.push(ptr->right);
                n--;
            }
            res.push_back(v);
            v.clear();
        }
        return res;
