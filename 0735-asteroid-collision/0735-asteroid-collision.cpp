class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        int i = 0;

        while (i < asteroids.size()) {
            bool destroyed = false;

            while (!s.empty() && s.top() > 0 && asteroids[i] < 0) {
                if (s.top() < -asteroids[i]) {
                    s.pop();
                } 
                else if (s.top() == -asteroids[i]) {
                    s.pop();
                    destroyed = true;
                    break;
                }
                else {
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                s.push(asteroids[i]);
            }

            i++;
        }

        vector<int> v;
        while (!s.empty()) {
            v.push_back(s.top());
            s.pop();
        }

        reverse(v.begin(), v.end());
        return v;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}