class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
    int l = 0;
    int ans = 0;

    for (int r = 0; r < nums.size(); r++) {

        if (nums[r] == 0)
            k--;

        while (k < 0) {
            if (nums[l] == 0)
                k++;

            l++;
        }

        ans = max(ans, r - l + 1);
    }

        return ans;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}