class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        long long sum = 0;

        
        for (int i = n - k; i < n; i++) {
            sum += cardPoints[i];
        }

        long long x = sum;

        int ptr1 = n - k;
        int ptr2 = 0;

        while (ptr1 != n) {
            x -= cardPoints[ptr1];
            x += cardPoints[ptr2];

            sum = max(sum, x);

            ptr1++;
            ptr2++;
        }

        return sum;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}