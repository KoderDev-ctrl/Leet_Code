class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int f1 = m - 1;
        int f2 = n - 1;
        int i = m + n - 1;

        while(f2 >= 0) {
            if(f1 >= 0 && nums1[f1] > nums2[f2]) {
                nums1[i] = nums1[f1];
                f1--;
            }
            else {
                nums1[i] = nums2[f2];
                f2--;
            }
            i--;
        }
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}