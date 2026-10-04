class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0;
        int mod = 1000000007;

        vector<int> prev(n), next(n);
        stack<int> s;

        for(int i = 0; i < n; i++) {
            while(!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }

            if(s.empty())
                prev[i] = -1;
            else
                prev[i] = s.top();

            s.push(i);
        }

        while(!s.empty())
            s.pop();

        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }

            if(s.empty())
                next[i] = n;
            else
                next[i] = s.top();

            s.push(i);
        }

        for(int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;

            sum = (sum + (long long)arr[i] * left * right) % mod;
        }

        return sum;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}