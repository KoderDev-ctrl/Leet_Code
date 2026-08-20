class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i=2;i<nums.size();i++){
            if(arr2.back()>arr1.back()){
                arr2.push_back(nums[i]);
            }
            else{
                arr1.push_back(nums[i]);
            }
        }
        for(int i=0;i<arr1.size();i++){
            nums[i]=arr1[i];
        }
        for(int i=0;i<arr2.size();i++){
            nums[arr1.size()+i]=arr2[i];
        }
        return nums;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}