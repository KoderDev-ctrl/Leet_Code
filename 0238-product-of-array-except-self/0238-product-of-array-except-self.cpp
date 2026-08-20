class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>v;
        v.push_back(1);
        int x=1;
        for(int i=1;i<nums.size();i++){
            v.push_back(nums[i-1]*x);
            x=v.back();
        }
        vector<int>u;
        u.push_back(1);
        int y=1;
        for(int i=nums.size()-2;i>=0;i--){
            u.push_back(nums[i+1]*y);
            y=u.back();
        }
        reverse(u.begin(),u.end());
        for(int i=0;i<v.size();i++){
            v[i]=v[i]*u[i];
        }
        return v;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}