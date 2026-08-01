class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) return s;

        string a = "";
        int cycle = 2 * numRows - 2;

        for (int j = 0; j < numRows; j++) {
            for (int i = j; i < s.length(); i += cycle) {
                a += s[i];
                int d = i + cycle - 2 * j;
                if (j != 0 && j != numRows - 1 && d < s.length()) {
                    a += s[d];
                }
            }
        }
        return a;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}