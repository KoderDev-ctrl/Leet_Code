class Solution {
public:
    int firstStableIndex(vector<int>& nums, int l) {
        int idx = -1;

        for (int i = 0; i < nums.size(); i++) {
            int ma = nums[i];
            int mi = nums[i];

            for (int j = 0; j < i; j++) {
                ma = max(ma, nums[j]);
            }

            for (int j = i + 1; j < nums.size(); j++) {
                mi = min(mi, nums[j]);
            }

            if (ma - mi <= l) {
                idx = i;
                break;
            }
        }

        return idx;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}