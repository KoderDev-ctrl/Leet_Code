class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // int negative = 0;
        // int positive = 0;
        // bool x = false;

        // for (int i = 0; i < nums.size(); i++) {
        //     x = !x;

        //     if (x) {
        //         if (nums[i] > 0) {
        //             positive++;
        //             continue;
        //         }

        //         while (positive < nums.size() && nums[positive] < 0) {
        //             positive++;
        //         }

        //         if (positive < nums.size()) {
        //             nums[i] = nums[positive];
        //             positive++;
        //         }
        //     }
        //     else {
        //         if (nums[i] < 0) {
        //             negative++;
        //             continue;
        //         }

        //         while (negative < nums.size() && nums[negative] > 0) {
        //             negative++;
        //         }

        //         if (negative < nums.size()) {
        //             nums[i] = nums[negative];
        //             negative++;
        //         }
        //     }
        // }

        // return nums;
        vector<int>p;
        vector<int>n;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){p.push_back(nums[i]);}
            else{
                n.push_back(nums[i]); 
            }
        }
        bool x=false;
        for(int i=0;i<nums.size();i++){
            if(!x){nums[i]=p[i/2];x=!x;}
            else{
                nums[i]=n[i/2];x=!x;
            }
        }
        return nums;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}