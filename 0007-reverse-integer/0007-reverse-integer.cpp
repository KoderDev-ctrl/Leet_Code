class Solution {
public:
    int reverse(int x) {
        long long num = x;
        bool neg = false;

        if (num < 0) {
            neg = true;
            num = -num;
        }

        long long y = 0;

        while (num > 0) {
            y = y * 10 + num % 10;
            num /= 10;
        }

        if (neg)
            y = -y;

        if (y > INT_MAX || y < INT_MIN)
            return 0;

        return (int)y;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}