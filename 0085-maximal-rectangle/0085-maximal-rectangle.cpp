class Solution {
        private: 
    vector<int> PrevSmallerIndex(vector<int>& heights) {
        stack<int> s; s.push(-1);
        vector<int> ans(heights.size());
        for(int i = 0; i < heights.size(); i++) {
            int curr = heights[i];
            while(s.top() != -1 && heights[s.top()] >= curr) {
                s.pop();
            }
            ans[i] = s.top();  
            s.push(i); 
        }
        return ans;
    }

    vector<int> NextSmallerIndex(vector<int>& heights) {
        stack<int> s; s.push(-1);
        vector<int> ans(heights.size());
        for(int i = heights.size() - 1; i >= 0; i--) {
            int curr = heights[i];
            while(s.top() != -1 && heights[s.top()] >= curr) {
                s.pop(); 
            }
            ans[i] = s.top(); 
            s.push(i);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> psi = PrevSmallerIndex(heights), nsi = NextSmallerIndex(heights);
        int maxi = INT_MIN;
        for(int i = 0; i < heights.size(); i++) {
            if(nsi[i] == -1) nsi[i] = heights.size();
            int l = heights[i], w = nsi[i] - psi[i] - 1;
            int area = l * w;
            maxi = max(area, maxi);
        }
        return maxi;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> v;
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n; i++) {
            vector<int> t;
            for(int j = 0; j < m; ++j) {
                t.push_back(matrix[i][j] - '0');
            }
            v.push_back(t);
        }
        int area = largestRectangleArea(v[0]);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; ++j) {
                if(v[i][j])    v[i][j] += v[i-1][j];
                else v[i][j] = 0;
            }
            area = max(area, largestRectangleArea(v[i]));
        }
        return area;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}