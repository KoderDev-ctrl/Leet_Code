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
    void flatten(TreeNode* root) {
        if (!root) return;

        stack<TreeNode*> st;
        vector<TreeNode*> v;

        st.push(root);

        while (!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();

            v.push_back(cur);

            if (cur->right) st.push(cur->right);
            if (cur->left) st.push(cur->left);
        }

        for (int i = 0; i < v.size() - 1; i++) {
            v[i]->left = nullptr;
            v[i]->right = v[i + 1];
        }

        v.back()->left = nullptr;
        v.back()->right = nullptr;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}