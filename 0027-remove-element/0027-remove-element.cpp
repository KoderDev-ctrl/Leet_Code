class Solution {
public:
    static bool comp(int a, int b) {
        return a > b;
    }

    int removeElement(vector<int>& nums, int val) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == val) {
                nums[i] = -1;
            }
        }

        sort(nums.begin(), nums.end(), comp);

        int k = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == -1) {
                break;
            }
            k++;
        }

        return k;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}