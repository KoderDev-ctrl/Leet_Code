class Solution {
public:
    int maxDepth(string s) {
        int c=0;
        int pc=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                pc++;
            }
            else if(s[i]==')'){
                c=max(c,pc);
                pc--;
            }
        }
        return c;
    }
};