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
    void dfs(TreeNode* node, bool& found, int cur_sum,int targetSum){
        if(found || node == NULL)
            return;
        
        int result = cur_sum + node->val ;
        
        
            //cout << "cur_sum: " << cur_sum <<"  cur node val: " << node->val << " result: " 
                //<< result << endl; 
            if(result == targetSum && (node->left==NULL && node->right ==NULL)){
                found = true;
                return;
            }
            if(node->left)
                dfs(node->left,found,result,targetSum);
            if(node->right)
                dfs(node->right,found,result,targetSum);
        
            
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool found = false;
        
        if(root==NULL)
            return false;
        if(root->val == targetSum && root->left==NULL && root->right==NULL)
            return true;
        
        int sum = root->val;
        dfs(root->left,found,sum,targetSum);
        dfs(root->right,found,sum,targetSum);
        
        return found;
    }
};

/*          1
        -2       -3
      1.  3.   -2   NULL
   -1



*/
