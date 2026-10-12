
class Solution {
public:
    int md(vector<int>& v, long long c) {
        int d = 1;
        long long x = 0;

        for (int i = 0; i < v.size(); i++) {
            if (x + v[i] <= c) {
                x += v[i];
            } else {
                d++;
                x = v[i];
            }
        }

        return d;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int mx = *max_element(weights.begin(), weights.end());

        long long sum = 0;
        for (int x : weights) {
            sum += x;
        }

        long long lo = mx;
        long long hi = sum;
        long long ans = sum;

        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;

            if (md(weights, mid) <= days) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}