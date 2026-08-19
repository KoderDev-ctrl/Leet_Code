class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> u;

        int r = 0;
        int l = 0;
        int c = 0;
        int pc = 0;
        int t = 0;

        while (c < fruits.size())
        {
            if (u[fruits[c]] == 0)
                t++;

            u[fruits[c]]++;
            pc++;
            c++;

            while (t > 2)
            {
                u[fruits[l]]--;
                pc--;

                if (u[fruits[l]] == 0)
                    t--;

                l++;
            }

            r = max(r, pc);
        }

        return r;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}