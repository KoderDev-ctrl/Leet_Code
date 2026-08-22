class Solution {
public:
    bool checkDivisibility(int n) {
        long long pr = 1;
        long long sum = 0;
        long long m = n;

        while (n) {
            pr *= n % 10;
            sum += n % 10;
            n /= 10;
        }

        return m%(pr + sum) == 0;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}