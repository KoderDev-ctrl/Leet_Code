class Solution {
public:
    int maxProduct(int n) {
        int max=n%10;
        int max1=(n/10)%10;
        n/=10;
        while(n){
            if(n%10>max){
                max1=max;
                max=n%10;
            }
            else if(n%10>max1){
                max1=n%10;
            }
            n/=10;
        }
        return max*max1;
    }
};