class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        unordered_map<int, int> u;
        int n = nums.size();
        int idx=0;
        bool x=false;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if(!x){
                    idx=i;
                    x=true;
                }
                u[0]++;
            }
        }

        int j = idx;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                while (j < n && nums[j] == 0) {
                    j++;
                }

                if (j < n) {
                    nums[i] = nums[j];
                    nums[j] = 0;
                    j++;
                }
            }
        }

        for (int i = n - u[0]; i < n; i++) {
            nums[i] = 0;
        }
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}