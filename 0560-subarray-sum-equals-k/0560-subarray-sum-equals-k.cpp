
class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int n = a.size();
        int p[n];
        p[0] = a[0];

        for (int i = 1; i < n; i++) {
            p[i] = a[i] + p[i - 1];
        }

        unordered_map<int, int> mp;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (p[i] == k)
                ans++;

            if (mp.find(p[i] - k) != mp.end()) {
                ans += mp[p[i] - k];
            }

            mp[p[i]]++;
        }

        return ans;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}