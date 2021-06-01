//Method-1:Recursion
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isLeaf(TreeNode* node)
    {
        if(node==NULL)
            return false;
        if(!node->left && !node->right)
            return true;
        return false;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int llSum = 0;//sum of the left leaves
        if(root==NULL)
            return 0;
        //we are going to check if the left child of a given node is a leaf node or not 
        if(isLeaf(root->left))
        {
            //if true then add the left node's value to the reqd sum
            llSum+=root->left->val;
        }
        //else we'll recur for the left subtree
        else
            llSum+=sumOfLeftLeaves(root->left);
        //recur for the right subtree and update the value of the required sum
        llSum+=sumOfLeftLeaves(root->right);
        return llSum;
    }
};

//Method-2:Breadth First Search
//Time Complexity:O(n)
//Space Complexity: O(n)

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL)
            return 0;
        int llSum = 0;
        queue<pair<TreeNode*,bool>> q;
        q.push(make_pair(root,0));
        while(!q.empty())
        {
            pair<TreeNode*,bool> p = q.front();
            q.pop();
            //check if the given node is a leaf node & a left child of it's parent
            if((!p.first->left && !p.first->right) && p.second)
            {
                llSum+=p.first->val;
            }
            //if not then enqueue the left & right child of the current popped node
            if(p.first->left)
                q.push(make_pair(p.first->left,1));
            if(p.first->right)
                q.push(make_pair(p.first->right,0));
        }
        return llSum;
    }
};
