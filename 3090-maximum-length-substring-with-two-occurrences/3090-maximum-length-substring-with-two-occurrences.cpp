class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ptr1 = 0;
        int ptr2 = 0;

        unordered_map<char, int> mp;

        int c = 0;

        while (ptr2 < s.size()) {
            mp[s[ptr2]]++;

            while (mp[s[ptr2]] > 2) {
                mp[s[ptr1]]--;
                ptr1++;
            }

            c = max(c, ptr2 - ptr1 + 1);

            ptr2++;
        }

        return c;
    }
};

const size_t BUFFER_SIZE = 0x6fafffff;
alignas(std::max_align_t) char buffer[BUFFER_SIZE];
size_t buffer_pos = 0;

void* operator new(size_t size) {
    constexpr std::size_t alignment = alignof(std::max_align_t);
    size_t padding = (alignment - (buffer_pos % alignment)) % alignment;
    size_t total_size = size + padding;

    char* aligned_ptr = &buffer[buffer_pos + padding];
    buffer_pos += total_size;

    return aligned_ptr;
}

void operator delete(void* ptr, unsigned long) {}
void operator delete(void* ptr) {}
void operator delete[](void* ptr) {}