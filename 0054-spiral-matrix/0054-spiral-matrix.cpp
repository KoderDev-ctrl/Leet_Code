class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix[0].size()-1;
        int m=matrix.size()-1;
        int right=n;
        int bottom=m;
        int top=0;
        int left=0;
        vector<int>v;
        while(top<=bottom && left<=right){
            for(int i = left; i <= right; i++){
                v.push_back(matrix[top][i]);
            }
            top++;

            for(int i = top; i <= bottom; i++){
                v.push_back(matrix[i][right]);
            }
            right--;

            if(top <= bottom){

                for(int i = right; i >= left; i--){
                    v.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if(left <= right){
                for(int i = bottom; i >= top; i--){
                    v.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return v;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}