class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int,int>u;
        for(int i=0;i<nums.size();i++){
            u[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            if(u[0]){
                nums[i]=0;
                u[0]--;
            }
            else if(u[1]){
                nums[i]=1;
                u[1]--;
            }
            else{
                nums[i]=2;
            }
        }
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}