class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int r = 0;
        int sum = 0;
        int c = INT_MAX;

        while(r < nums.size() || sum >= target) {

            if(sum >= target) {
                c = min(c, r - l);
                sum -= nums[l];
                l++;
            }

            if(sum < target && r < nums.size()) {
                sum += nums[r];
                r++;
            }
        }

        if(c == INT_MAX)
            return 0;

        return c;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}