//Method - 1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findPath(TreeNode* root,TreeNode* node,vector<int>& path)
    {
        if(root==NULL)
            return false;
        path.push_back(root->val);
        if(root->val==node->val)
            return true;
        //check if the node is present in the left or right subtree
        if(root->left!=NULL && (findPath(root->left,node,path))||root->right!=NULL &&
          (findPath(root->right,node,path)))
            return true;
        //if the node is not present then remove node from the path and return false
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return NULL;
        //vector to store the paths from the root to the nodes p & q;
        vector<int> p1,p2;
        if(!findPath(root,p,p1) || !findPath(root,q,p2))
            return NULL;
        //traverse both the paths till the same values
        int i=0;
        for(i=0;i<p1.size() && i<p2.size();i++)
        {
            if(p1[i]!=p2[i])
                break;
        }
        TreeNode* lca=new TreeNode(p1[i-1]);
        return lca;
    }
};
