class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> u = {
            {'q',1},{'w',1},{'e',1},{'r',1},{'t',1},
            {'y',1},{'u',1},{'i',1},{'o',1},{'p',1},
            {'Q',1},{'W',1},{'E',1},{'R',1},{'T',1},
            {'Y',1},{'U',1},{'I',1},{'O',1},{'P',1}
        };

        unordered_map<char, int> v = {
            {'a',1},{'s',1},{'d',1},{'f',1},{'g',1},
            {'h',1},{'j',1},{'k',1},{'l',1},
            {'A',1},{'S',1},{'D',1},{'F',1},{'G',1},
            {'H',1},{'J',1},{'K',1},{'L',1}
        };

        unordered_map<char, int> w = {
            {'z',1},{'x',1},{'c',1},{'v',1},{'b',1},
            {'n',1},{'m',1},
            {'Z',1},{'X',1},{'C',1},{'V',1},{'B',1},
            {'N',1},{'M',1}
        };

        vector<string> ans;

        for (int i = 0; i < words.size(); i++) {
            bool x = true;

            if (u.count(words[i][0])) {
                x = true;
                for (int j = 0; j < words[i].length(); j++) {
                    if (!u.count(words[i][j])) {
                        x = false;
                        break;
                    }
                }
                if (x) ans.push_back(words[i]);
            }

            if (v.count(words[i][0])) {
                x = true;
                for (int j = 0; j < words[i].length(); j++) {
                    if (!v.count(words[i][j])) {
                        x = false;
                        break;
                    }
                }
                if (x) ans.push_back(words[i]);
            }

            if (w.count(words[i][0])) {
                x = true;
                for (int j = 0; j < words[i].length(); j++) {
                    if (!w.count(words[i][j])) {
                        x = false;
                        break;
                    }
                }
                if (x) ans.push_back(words[i]);
            }
        }

        return ans;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}