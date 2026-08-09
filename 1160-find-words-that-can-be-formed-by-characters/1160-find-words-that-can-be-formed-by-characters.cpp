class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int>hash(26,0);
        for(int i=0;i<chars.length();i++){
            hash[chars[i]-'a']++;
        }
        int c=0;
        for(int j=0;j<words.size();j++){
            vector<int>hash1(hash);
            int count=0;
            for(int i=0;i<words[j].length();i++){
                if(!hash1[words[j][i]-'a']){
                    count=0;
                    break;
                }
                else{
                    hash1[words[j][i]-'a']--;
                    count++;
                }
            }
            c+=count;
        }
        return c;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}