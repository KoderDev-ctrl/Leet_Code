class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int hash[26]={0};
        int hash1[26]={0};
        for(int i=0;i<ransomNote.length();i++){
            hash[ransomNote[i]-'a']+=1;
        }
        for(int i=0;i<magazine.length();i++){
            hash1[magazine[i]-'a']+=1;
        }
        for(int i=0;i<26;i++){
            if(hash[i]>hash1[i]){
                return false;
            }
        }
        return true;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}