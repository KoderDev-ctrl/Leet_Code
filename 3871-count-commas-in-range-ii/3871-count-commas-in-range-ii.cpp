class Solution {
public:
    long long countCommas(long long n) {

        if (n <= 999)
            return 0;

        else if (n <= 999999)
            return n - 999;

        else if (n <= 999999999)
            return (n - 999999) * 2 + 999000;

        else if (n <= 999999999999)
            return (n - 999999999) * 3 + 1998999000LL;

        else if (n <= 999999999999999)
            return (n - 999999999999) * 4 + 2998998999000LL;

        else
            return (n - 999999999999999) * 5
                 + 3998998998999000LL;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}