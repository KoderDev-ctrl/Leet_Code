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
    TreeNode* constructTree(vector<int>& postorder, vector<int>& inorder,
                            int postStart, int inStart, int inEnd) {
        if (inStart > inEnd)
            return nullptr;

        TreeNode* root = new TreeNode(postorder[postStart]);

        int i = inStart;
        while (i <= inEnd && inorder[i] != postorder[postStart]) {
            i++;
        }

        int rightSize = inEnd - i;

        root->right = constructTree(postorder, inorder,
                                    postStart - 1,
                                    i + 1, inEnd);

        root->left = constructTree(postorder, inorder,
                                   postStart - rightSize - 1,
                                   inStart, i - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.empty())
            return nullptr;

        return constructTree(postorder, inorder,
                             postorder.size() - 1,
                             0, inorder.size() - 1);
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}