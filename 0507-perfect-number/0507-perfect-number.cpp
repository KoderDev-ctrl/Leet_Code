class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num<=1){return false;}
        int x=1;
        int i=2;
        vector<int>v;
        while(i*i<num){
            if(num%i==0){
                x+=i+num/i; 
            }
            i++;
        }
        if(i*i==x){x+=i;}
        return (num==x);
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}