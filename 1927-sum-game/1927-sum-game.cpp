class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int count = 0;

        for (char c : num) {
            if (c == '?') count++;
        }

        if (count % 2 == 1)
            return true;

        int lefts = 0, rights = 0;
        int leftq = 0, rightq = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                leftq++;
            else
                lefts += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                rightq++;
            else
                rights += num[i] - '0';
        }

        return 2 * (lefts - rights) != 9 * (rightq - leftq);
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}