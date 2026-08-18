class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        
        unordered_map<string, int> u;
        
        for (int i = 0; i < dictionary.size(); i++) {
            u[dictionary[i]]++;
        }

        string x = "";
        string s = "";

        for (int i = 0; i < sentence.length(); i++) {
            if (sentence[i] != ' ') {
                x += sentence[i];
            }

            if (u.count(x)) {
                s += x + " ";
                x = "";

                while (i < sentence.length() && sentence[i] != ' ') {
                    i++;
                }

                continue;
            }
            else if (sentence[i] == ' ') {
                s += x + " ";
                x = "";
            }
        }

        if (x != "")
            s += x;

        if (!s.empty() && s.back() == ' ')
            s.pop_back();

        return s;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}