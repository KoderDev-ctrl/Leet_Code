class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> u;

        for (char c : s)
            u[c]++;

        vector<int> v;

        while (u['z'] && u['e'] && u['r'] && u['o']) {
            v.push_back(0);
            u['z']--;
            u['e']--;
            u['r']--;
            u['o']--;
        }

        while (u['t'] && u['w'] && u['o']) {
            v.push_back(2);
            u['t']--;
            u['w']--;
            u['o']--;
        }

        while (u['f'] && u['o'] && u['u'] && u['r']) {
            v.push_back(4);
            u['f']--;
            u['o']--;
            u['u']--;
            u['r']--;
        }

        while (u['s'] && u['i'] && u['x']) {
            v.push_back(6);
            u['s']--;
            u['i']--;
            u['x']--;
        }

        while (u['e'] && u['i'] && u['g'] && u['h'] && u['t']) {
            v.push_back(8);
            u['e']--;
            u['i']--;
            u['g']--;
            u['h']--;
            u['t']--;
        }

        while (u['t'] && u['h'] && u['r'] && u['e'] >= 2) {
            v.push_back(3);
            u['t']--;
            u['h']--;
            u['r']--;
            u['e'] -= 2;
        }

        while (u['f'] && u['i'] && u['v'] && u['e']) {
            v.push_back(5);
            u['f']--;
            u['i']--;
            u['v']--;
            u['e']--;
        }

        while (u['s'] && u['e'] >= 2 && u['v'] && u['n']) {
            v.push_back(7);
            u['s']--;
            u['e'] -= 2;
            u['v']--;
            u['n']--;
        }

        while (u['o'] && u['n'] && u['e']) {
            v.push_back(1);
            u['o']--;
            u['n']--;
            u['e']--;
        }

        while (u['n'] >= 2 && u['i'] && u['e']) {
            v.push_back(9);
            u['n'] -= 2;
            u['i']--;
            u['e']--;
        }

        sort(v.begin(), v.end());

        string ans;
        for (int i = 0; i < v.size(); i++)
            ans += char('0' + v[i]);

        return ans;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}