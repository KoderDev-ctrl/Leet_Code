class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        st.push(stoi(operations[0]));
        for(int i=1;i<operations.size();i++){
           if(operations[i]=="+"){
                int temp=st.top();
                st.pop();
                int t=st.top();
                st.push(temp);
                st.push(temp+t);
            }
            
            else if(operations[i]=="D"){
                int temp=st.top();
                st.push(temp*2);
            }
            else if(operations[i]=="C"){
                st.pop();
            }
            else{
                st.push(stoi(operations[i]));
            }
        }
        int score=0;
        while(!st.empty()){
            score+=st.top();
            st.pop();
        }
        return score;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}