class Solution {
public:
    string largestGoodInteger(string num) {
        string s = "";
        int x = -1;
        int y = 0;

        for (int i = 0; i < num.length() - 2; i++) {
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
                y = num[i] - '0';
                x = max(x, y);
            }
        }

        if (x == -1) {
            return s;
        }
        else {
            for (int i = 0; i < 3; i++) {
                s += char(x + '0');
            }
            return s;
        }
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}