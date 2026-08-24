class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> v;

        for (int i = 0; i < words.size();) {
            int j = i, l = 0;

            while (j < words.size() &&
                   l + words[j].size() + (j - i) <= maxWidth) {
                l += words[j].size();
                j++;
            }

            int x = j - i;
            int s = maxWidth - l;
            string t;

            if (j == words.size() || x == 1) {
                for (int k = i; k < j; k++) {
                    if (k > i)
                        t += ' ';
                    t += words[k];
                }

                for (int k = t.size(); k < maxWidth; k++)
                    t += ' ';
            }
            else {
                int g = x - 1;
                int a = s / g;
                int b = s % g;

                for (int k = i; k < j; k++) {
                    t += words[k];

                    if (k < j - 1) {
                        for (int z = 0; z < a; z++)
                            t += ' ';
                        if (k - i < b)
                            t += ' ';
                    }
                }
            }

            v.push_back(t);
            i = j;
        }

        return v;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}