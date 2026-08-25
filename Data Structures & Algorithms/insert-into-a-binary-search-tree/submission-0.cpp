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
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        if(root == NULL){
            return new TreeNode(val);
        }

        TreeNode* cur = root;
        while(true){
            //the given element is bigger than root so we traverse on right side of root
            if(cur -> val <= val){
                if(cur -> right != NULL){
                    cur = cur -> right;
                }
                else if(cur -> right == NULL){
                    cur -> right = new TreeNode(val);
                    break; //insert the node
                }
            }
            else{
                //the given element is smaller than root so we traverse on left side of root
                if(cur -> left != NULL){
                    cur = cur -> left;
                }
                else{
                    cur -> left = new TreeNode(val);
                    break;
                }
            }
        }

        return root;
        
    }
};