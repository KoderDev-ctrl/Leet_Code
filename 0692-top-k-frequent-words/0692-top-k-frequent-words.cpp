class Solution {
public:
    static bool comp(pair<int, string>& a, pair<int, string>& b) {
        if (a.first != b.first)
            return a.first > b.first;
        return a.second < b.second;
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> u;

        for (int i = 0; i < words.size(); i++) {
            u[words[i]]++;
        }

        vector<pair<int, string>> v;

        for (auto it = u.begin(); it != u.end(); it++) {
            v.push_back({it->second, it->first});
        }

        sort(v.begin(), v.end(), comp);

        vector<string> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(v[i].second);
        }

        return ans;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}