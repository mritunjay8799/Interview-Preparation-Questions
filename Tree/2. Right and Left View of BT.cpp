"SOLUTION" - TRAVERSE THE TREE IN LEVEL ORDER AND FOR "LEFT VIEW" THE "FIRST ELEMENT OF EACH LEVEL" MAKES LEFT VIEW AND "LAST ELEMENT OF EACH LEVEL" MAKES "RIGHT VIEW"
    
 EG : 
                        4
                      /   \
                     5     6
                   /  \   /  \
                  7    8 9    10
                         
"LEVEL ORDER":   4
                 5 6
                 7 8 9 10
    "LEFT VIEW" - 4 5 7
    "RIGHT VIEW" - 4 6 10



RIGHT VIEW-
-----------

class Solution {
public:
    
    void rightutil(TreeNode* root, int level, int *max_level, vector<int>&res)
    {
        if(root == NULL)
            return;
        if(*max_level < level)
        {
            res.push_back(root->val);
            *max_level = level;
        }
        rightutil(root->right, level+1, max_level, res);
        rightutil(root->left, level+1, max_level, res);
        return;
    }
    
    vector<int> rightSideView(TreeNode* root) {
        int max_level = 0;
        vector<int>res;
        rightutil(root, 1,&max_level, res);
        return res;
        
    }
};

===================================================================================================================================================================================

LEFT VIEW- "METHOD:1 USING NESTED LOOPS"
--------------------------------------
    
void solve(Node* root, vector<int>&v)
{
    if(root==NULL)
        return;
   queue<Node*>q;
   q.push(root);
   while(!q.empty())
   {
       int n = q.size();
       for(int i =0;i<n;i++)
       {
            auto a = q.front();
            q.pop();
            if(i==0)
                v.push_back(a->data);
        if(a->left)
            q.push(a->left);
        if(a->right)
            q.push(a->right);    
       }
   }
}
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int>v;
   solve(root,v);
   return v;
}

================================================================================================================================================================================

 "METHOD 2 - USING RECURSION"
 -----------------------------
    
class Solution {
public:
    
    void leftutil(TreeNode* root, int level, int *max_level, vector<int>&res)
    {
        if(root == NULL)
            return;
        if(*max_level < level)
        {
            res.push_back(root->val);
            *max_level = level;
        }
        leftutil(root->left, level+1, max_level, res);
        lefttutil(root->right, level+1, max_level, res);
        return;
    }
    
    vector<int> rightSideView(TreeNode* root) {
        int max_level = 0;
        vector<int>res;
        leftutil(root, 1,&max_level, res);
        return res;
        
    }
};
