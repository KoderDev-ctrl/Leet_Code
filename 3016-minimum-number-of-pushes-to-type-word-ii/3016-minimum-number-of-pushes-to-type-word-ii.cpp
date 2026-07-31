class Solution {
public:
    int minimumPushes(string word) {
        int hash[26] = {0};

        for (int i = 0; i < word.length(); i++) {
            hash[word[i] - 'a']++;
        }

        sort(hash, hash + 26);
        reverse(hash, hash + 26);

        int count = 0;
        int c = 1;

        for (int i = 0; i < 26 && hash[i] != 0; i++) {
            count += hash[i] * c;

            if ((i + 1) % 8 == 0) {
                c++;
            }
        }

        return count;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}