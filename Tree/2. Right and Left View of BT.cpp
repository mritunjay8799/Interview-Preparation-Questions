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

LEFT VIEW-
----------

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
