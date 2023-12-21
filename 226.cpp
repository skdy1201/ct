#include <queue>
using std::queue;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 class Solution {
 public:

     queue<TreeNode*> swapnode;

     TreeNode* invertTree(TreeNode* root) {

         if (root == NULL)
             return NULL;
         invertTree(root->left); 
         invertTree(root->right);
   
         TreeNode* temp = root->right;
         swapnode.push(temp);
         swapnode.push(root->left);
        
         root->right = swapnode.front();

         swapnode.pop();

         root->left = swapnode.front();

         swapnode.pop();

         return root;
     }
 };