
class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        int n = arr.size();
        long long maxi = 0, mini = 0;
        vector<int> prev(n), next(n);
        stack<int> s;

        // Sum of subarray minimums
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] > arr[i])
                s.pop();

            prev[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        while (!s.empty()) s.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();

            next[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        for (int i = 0; i < n; i++)
            mini += 1LL * arr[i] * (i - prev[i]) * (next[i] - i);

        while (!s.empty()) s.pop();

        // Sum of subarray maximums
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] < arr[i])
                s.pop();

            prev[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        while (!s.empty()) s.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] <= arr[i])
                s.pop();

            next[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        for (int i = 0; i < n; i++)
            maxi += 1LL * arr[i] * (i - prev[i]) * (next[i] - i);

        return maxi - mini;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}