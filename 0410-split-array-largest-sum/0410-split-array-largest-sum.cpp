class Solution {
public:
    bool ca(vector<int>& a, int k, long long lim) {
        int cnt = 1;
        long long sum = 0;

        for (int x : a) {
            if (sum + x <= lim) {
                sum += x;
            } else {
                cnt++;
                sum = x;
            }

            if (cnt > k) return false;
        }

        return true;
    }

int splitArray(vector<int>& a, int k) {
        long long l = a[0], r = 0;

        for (int x : a) {
            l = max(l, (long long)x);
            r += x;
        }

        while (l < r) {
            long long m = l + (r - l) / 2;

            if (ca(a, k, m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return (int)l;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}