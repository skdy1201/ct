#include <list>
using std::list;

#include <vector>
using std::vector;

#include <algorithm>
#include <stdlib.h>
using std::max;

#include <iostream>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


//class Solution {
//public:
//
//    int count;
//    
//    vector<int> goleft;
//    vector<int> goright;
//    TreeNode* ParentNode;
//
//
//
//    int findsun(TreeNode* tree)
//    {
//        if (tree->left != nullptr)
//        {
//            goleft.push_back(tree->val);
//            ParentNode = tree;
//            tree = tree->left;
//            findsun(tree);
//        }
//        else if(tree->left == nullptr && tree->right != nullptr)
//        {
//            goleft.push_back(tree->val);
//            ParentNode = tree;
//            tree = tree->right;
//            findsun(tree);
//        }
//        else
//        {
//            int count = goleft.size();
//
//            if (goleft.size() > count)
//                count = goleft.size();
//
//            tree = ParentNode;
//            findsun(tree);
//        }
//
//        if (tree->right != nullptr)
//        {
//            goright.push_back(tree->val);
//            ParentNode = tree;
//            tree = tree->left;
//            findsun(tree);
//        }
//        else if (tree->left == nullptr && tree->right != nullptr)
//        {
//            goright.push_back(tree->val);
//            ParentNode = tree;
//            tree = tree->right;
//            findsun(tree);
//        }
//        else
//        {
//            if (goright.size() > count)
//                count = goright.size();
//
//            tree = ParentNode;
//            findsun(tree);
//        }
//
//        return count;
//    }
//
//
//    int maxDepth(TreeNode* root) {
//
//       return findsun(root);
//    }
//    
//};


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        return max(lh, rh) + 1;
    }
};


int maxDepth(TreeNode* root) {
    if (root == NULL)
        return 0;
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return max(lh, rh) + 1;
}


int main() {
    TreeNode* pTree = new TreeNode(3);
    pTree->left = new TreeNode(9);
    pTree->right = new TreeNode(20);
    pTree->right->left = new TreeNode(15);
    pTree->right->right = new TreeNode(7);

    // 추가적인 작업 수행...

    maxDepth(pTree);

    // 메모리 누수 방지를 위해 동적으로 할당된 노드들을 삭제
    delete pTree->right->right;
    delete pTree->right->left;
    delete pTree->right;
    delete pTree->left;
    delete pTree;

    return 0;
}
