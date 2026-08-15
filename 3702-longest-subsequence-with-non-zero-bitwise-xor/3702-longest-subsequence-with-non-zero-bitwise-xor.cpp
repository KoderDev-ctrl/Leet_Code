class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr = 0;
        int c = 0;

        for (int i = 0; i < nums.size(); i++) {
            xr ^= nums[i];

            if (nums[i] != 0)
                c = 1;
        }

        if (xr != 0)
            return nums.size();

        if (c)
            return nums.size() - 1;

        return 0;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}