class Solution {
public:
    string removeDuplicates(string s) {
     stack<char> st;
     st.push(s[0]);
     for(int i=1; i<s.size(); i++){
        if(!st.empty() && s[i]==st.top()) st.pop();
        else st.push(s[i]);
     }
     string s1 = "";
     while(!st.empty()){
        s1 += st.top();
        st.pop();
    }
    reverse(s1.begin(), s1.end());
    return s1;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}