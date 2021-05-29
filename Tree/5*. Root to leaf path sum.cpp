Given a binary tree of N nodes, where every node value is a number. Find the sum of all the numbers which are formed from root to leaf paths.

Example 1:
Input :      
           6                               
         /   \                          
        3     5                      
      /   \     \
     2    5      4             
        /  \                        
       7    4  

Output: 13997

Explanation :
There are 4 leaves, hence 4 root to leaf paths:
Path                      Number
6->3->2                   632
6->3->5->7                6357
6->3->5->4                6354
6->5>4                    654   
Answer = 632 + 6357 + 6354 + 654 = 13997 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(Height of Tree)

=================================================================================================================================================================================
// C++ program to find sum of
// all paths from root to leaves 
#include <bits/stdc++.h>
using namespace std;

class node 
{ 
    public:
    int data; 
    node *left, *right; 
}; 

// function to allocate new node with given data 
node* newNode(int data) 
{ 
    node* Node = new node();
    Node->data = data; 
    Node->left = Node->right = NULL; 
    return (Node); 
} 

// Returns sum of all root to leaf paths.
// The first parameter is root 
// of current subtree, the second 
// parameter is value of the number formed 
// by nodes from root to this node 
int treePathsSumUtil(node *root, int val) 
{ 
    // Base case 
    if (root == NULL) return 0; 

    // Update val 
    val = (val*10 + root->data); 

    // if current node is leaf, return the current value of val 
    if (root->left==NULL && root->right==NULL) 
    return val; 

    // recur sum of values for left and right subtree 
    return treePathsSumUtil(root->left, val) + 
        treePathsSumUtil(root->right, val); 
} 

// A wrapper function over treePathsSumUtil() 
int treePathsSum(node *root) 
{ 
    // Pass the initial value as 0
    // as there is nothing above root 
    return treePathsSumUtil(root, 0); 
} 

// Driver code
int main() 
{ 
    node *root = newNode(6); 
    root->left = newNode(3); 
    root->right = newNode(5); 
    root->left->left = newNode(2); 
    root->left->right = newNode(5); 
    root->right->right = newNode(4); 
    root->left->right->left = newNode(7); 
    root->left->right->right = newNode(4); 
    cout<<"Sum of all paths is "<<treePathsSum(root); 
    return 0; 
} 

