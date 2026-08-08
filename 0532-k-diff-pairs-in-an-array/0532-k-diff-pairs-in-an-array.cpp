class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;

        sort(nums.begin(), nums.end());

        int i = 0, j = 1;
        int count = 0;

        while (j < nums.size()) {

            if (i == j) {
                j++;
                continue;
            }

            int diff = nums[j] - nums[i];

            if (diff < k) {
                j++;
            }
            else if (diff > k) {
                i++;
            }
            else {
                count++;

                int left = nums[i];
                int right = nums[j];

                while (i < nums.size() && nums[i] == left)
                    i++;

                while (j < nums.size() && nums[j] == right)
                    j++;
            }
        }

        return count;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}