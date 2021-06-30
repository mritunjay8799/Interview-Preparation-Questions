Example Input
Input 1:

      6
    /   \
   3     7
  / \     \
 2   5     9
        
Example Output
Output 1:

 [
    [2],
    [3],
    [6, 5],
    [7],
    [9]
 ]
___________________________________________________________________________________________________________________________________________________________________________________

vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    vector<vector<int> >vect;
    if(A==NULL)
    return vect;
    
    map<int, vector<int> >hash;
    queue<pair<TreeNode*,int> >q;
    q.push(make_pair(A,0));
    while(!q.empty())
    {
        pair<TreeNode*,int>p1 = q.front();
        q.pop();
        TreeNode* temp = p1.first;
        int count = p1.second;
        hash[count].push_back(temp->val);
        if(temp->left!=NULL)
        {
            q.push(make_pair(temp->left,count-1));
        }
        if(temp->right!=NULL)
        {
            q.push(make_pair(temp->right,count+1));
        }
        free(temp);
    }
    map<int,vector<int> >::iterator it;
    for(it=hash.begin();it!=hash.end();it++)
    {
        vect.push_back(it->second);
    }
    return vect;
}
