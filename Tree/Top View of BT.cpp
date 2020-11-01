
Given below is a binary tree. The task is to print the top view of binary tree.
Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Print from leftmost node to rightmost node.

===================================================================================================================================================================================

void topUtil(struct Node *root, int index, int level,  map<int,pair<int,int> >&mp)
{
    if(root == NULL)
        return;
    if(mp.count(index) == 0)
        mp[index] = make_pair(root->data,level);
    else if(mp[index].second > level)
        mp[index] = make_pair(root->data, level);
    topUtil(root->left,index-1,level+1,mp);
    topUtil(root->right,index+1,level+1,mp);
    return;
}
void topView(struct Node *root)
{
    //Your code here
    map<int,pair<int,int> >mp;
    topUtil(root, 0,0,mp);
    for(auto i = mp.begin(); i!=mp.end();i++)
    {
        cout<<i->second.first<<" ";
    }
}
