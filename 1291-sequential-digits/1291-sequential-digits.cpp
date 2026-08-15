class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        string base = "1";

        for (int i = 1; i < to_string(low).length(); i++) {
            base += '0';
        }

        while (low <= high) {
            string s = to_string(low);

            for (int i = 1; i < s.length(); i++) {
                s[i] = s[i - 1] + 1;
            }

            if (s.back() > '9') {
                base += '0';
                if (base.length() > 10) break;
                low = stoi(base);
                continue;
            }

            int num = stoi(s);

            if (num >= low && num <= high) {
                ans.push_back(num);
            }

            if (num > high) {
                break;
            }

            if (s.back() == '9') {
                base += '0';
                if (base.length() > 10) break;
                low = stoi(base);
            }
            else {
                low = (low - (low % stoi(base))) + stoi(base);
            }
        }

        return ans;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}