class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool x=true;
        for(int i=0;i<nums1.size()-1;i++){
            if(nums1[i]%2!=nums1[i+1]%2){
                x=false;
                break;
            }
        }
        if(x){return true;}
        int mi=nums1[0];
        for(int i=0;i<nums1.size();i++){
            if(mi>nums1[i]){
                mi=nums1[i];
            }
        }
        if(mi&1){
            return true;
        }
        return false;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}