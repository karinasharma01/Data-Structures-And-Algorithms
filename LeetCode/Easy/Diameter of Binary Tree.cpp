//Method-1 
//Time Complexity - O(n^2)
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
    int height(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return max(height(root->left),height(root->right))+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        int leftH = height(root->left);
        int rightH = height(root->right);
        int d1 = leftH + rightH;
        int d2 = diameterOfBinaryTree(root->left);
        int d3 = diameterOfBinaryTree(root->right);
        return max(d1,max(d2,d3));
        
    }
};

//Method-2:
//Time Complexity : O(n)
class Solution {
public:
    pair<int,int> helper(TreeNode* root)
    {
        if(root==NULL)
        {
            pair<int,int> p;
            p.first=0;
            p.second=0;
            return p;
        }
        pair<int,int> leftAns = helper(root->left);
        pair<int,int> rightAns = helper(root->right);
        int leftH = leftAns.first;
        int leftD = leftAns.second;
        int rightH = rightAns.first;
        int rightD = rightAns.second;
        int height = max(leftH,rightH)+1;
        int diameter = max(leftH+rightH,max(leftD,rightD));
        pair<int,int> p;
        p.first=height;
        p.second = diameter;
        return p;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> ans = helper(root);
        int diameter = ans.second;
        return diameter;
    }
};
