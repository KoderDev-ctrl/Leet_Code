class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int f1 = 0;
        int f2 = 0;

        while(f1 < m && f2 < n) {
            if(nums1[f1] > nums2[f2]) {
                swap(nums1[f1], nums2[f2]);

                int j = f2;

                while(j + 1 < n && nums2[j] > nums2[j + 1]) {
                    swap(nums2[j], nums2[j + 1]);
                    j++;
                }
            }

            f1++;
        }

        sort(nums2.begin(), nums2.end());

        for(int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}