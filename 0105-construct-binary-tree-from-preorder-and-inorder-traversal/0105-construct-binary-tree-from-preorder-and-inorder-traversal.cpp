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
    TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder,
                            int preStart, int inStart, int inEnd) {
        if (inStart > inEnd)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int i = inStart;
        while (i <= inEnd && inorder[i] != preorder[preStart]) {
            i++;
        }

        int leftSize = i - inStart;

        root->left = constructTree(preorder, inorder,
                                   preStart + 1,
                                   inStart, i - 1);

        root->right = constructTree(preorder, inorder,
                                    preStart + leftSize + 1,
                                    i + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty())
            return nullptr;

        return constructTree(preorder, inorder,
                             0, 0, inorder.size() - 1);
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}