class Solution {
public:
    int minDays(vector<int>& a, int m, int k) {
        if ((long long)m * k > a.size()) return -1;

        int l = *min_element(a.begin(), a.end());
        int r = *max_element(a.begin(), a.end());

        while (l < r) {
            int mid = l + (r - l) / 2, b = 0, f = 0;

            for (int d : a) {
                if (d <= mid) {
                    if (++f == k) {
                        b++;
                        f = 0;
                    }
                } else {
                    f = 0;
                }
            }

            if (b >= m) r = mid;
            else l = mid + 1;
        }

        return l;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}