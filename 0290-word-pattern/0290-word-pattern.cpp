class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        vector<string> v;
        string x = "";
        bool t = false;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                if (t)
                {
                    v.push_back(x);
                }
                t = false;
                x = "";
                continue;
            }
            else
            {
                x += s[i];
                t = true;
            }
        }
        if (t)
        {
            v.push_back(x);
        }
        if(pattern.length()!=v.size()){return false;}
        unordered_map<char, string> u;
        unordered_map<string,char> U;
        for (int i = 0; i < pattern.length(); i++)
        {
            if (!u.count(pattern[i]))
            {
                u[pattern[i]] = v[i];
            }
            else
            {
                if (u[pattern[i]] != v[i])
                {
                    return false;
                }
            }
            if (!U.count(v[i]))
            {
                U[v[i]] = pattern[i];
            }
            else
            {
                if (U[v[i]] != pattern[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}