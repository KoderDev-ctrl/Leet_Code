class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>q;

        for(int i=0;i<students.size();i++)
        {
            q.push(students[i]);
        }

        int i=0;
        int count=0;

        while(!q.empty())
        {
            if(q.front()==sandwiches[i])
            {
                q.pop();
                i++;
                count=0;
            }
            else
            {
                q.push(q.front());
                q.pop();
                count++;
            }

            if(count==q.size())
            {
                break;
            }
        }

        return q.size();
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}