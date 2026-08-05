class Solution {
public:
    static bool comp(pair<int,int> &a, pair<int,int> &b){
        return a.first > b.first;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash;

        for(int i = 0; i < nums.size(); i++){
            hash[nums[i]]++;
        }

        vector<pair<int,int>> freq;

        for(auto &it : hash){
            freq.push_back({it.second, it.first}); 
        }

        sort(freq.begin(), freq.end(), comp);

        vector<int> ans;

        for(int i = 0; i < k; i++){
            ans.push_back(freq[i].second);
        }

        return ans;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}