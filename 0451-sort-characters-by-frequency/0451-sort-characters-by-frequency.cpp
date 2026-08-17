class Solution {
public:
static bool comp(pair<int,char>a,pair<int,char>b){
    return a.first>b.first;
}
    string frequencySort(string s) {
        unordered_map<char,int> u;
        for(int i=0;i<s.length();i++){
            u[s[i]]++;
        }
        vector<pair<int,char>>v;
        for(auto it=u.begin();it!=u.end();it++){
            v.push_back({it->second,it->first});
        }
        sort(v.begin(),v.end(),comp);
        int k=0;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].first;j++){
               s[k]=char(v[i].second);
               k++;
            }
        }
        return s;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}