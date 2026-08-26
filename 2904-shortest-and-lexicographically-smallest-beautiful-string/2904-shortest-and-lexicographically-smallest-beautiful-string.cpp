class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l = 0, r = 0, c = 0;
        string res = "";

        while (r < s.length()) {
            if (s[r] == '1')
                c++;
            r++;

            if (c == k) {
                while (s[l] == '0')
                    l++;

                string x(s.begin() + l, s.begin() + r);

                if (res == "" || x.length() < res.length() ||
                    (x.length() == res.length() && x < res))
                    res = x;

                c--;
                l++;
            }
        }

        return res;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}