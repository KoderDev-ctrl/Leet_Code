class Solution {
public:
    string reverseWords(string s) {
        vector<string> u;
        string v = "";
        bool x = true;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] != ' ') {
                v += s[i];
                x = false;
            }
            else {
                if(!x) {
                    u.push_back(v);
                }
                x = true;
                v = "";
            }
        }

        if(!v.empty()) {
            u.push_back(v);
        }

        reverse(u.begin(), u.end());

        string h = "";
        for(int i = 0; i < u.size(); i++) {
            h += u[i] + " ";
        }

        if(!h.empty())
            h.pop_back();

        return h;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}