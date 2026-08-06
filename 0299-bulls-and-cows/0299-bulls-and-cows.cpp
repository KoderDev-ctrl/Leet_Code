class Solution {
public:
    string getHint(string secret, string guess) {
        int hash[10]={0};
        int hash1[10]={0};
        for(int i=0;i<guess.length();i++){
            hash[guess[i]-'0']+=1;
            hash1[secret[i]-'0']+=1;
        }
        int y=0;
        for(int i=0;i<guess.length();i++){
            if(guess[i]==secret[i]){
                y++;
                hash[guess[i]-'0']-=1;
                hash1[secret[i]-'0']-=1;
            }
        }
        int x=0;
        for(int i=0;i<10;i++){
            if(hash[i]>hash1[i]){
                x+=hash1[i];
            }
            else if(hash1[i]){
                x+=hash[i];
            }
        }
        string s= "";
        s+=to_string(y)+"A"+to_string(x)+"B";
        return s;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}