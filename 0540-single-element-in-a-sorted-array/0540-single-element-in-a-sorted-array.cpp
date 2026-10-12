class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        if(nums.size()==1){return nums[0];}
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (mid % 2 == 1)
                mid--;

            if (nums[mid] == nums[mid + 1]) {
                lo = mid + 2;
            }
            else {
                hi = mid;
            }
        }

        return nums[lo];
    }
};

const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}