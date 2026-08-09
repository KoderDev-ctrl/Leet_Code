class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        vector<int> hash(2001, 0);

        for (int i = 0; i < arr.size(); i++) {
            hash[arr[i] + 1000]++;
        }

        for (int i = 0; i < arr.size(); i++) {
            int x = arr[i];

            int twice = 2 * x;
            if (twice >= -1000 && twice <= 1000) {
                if (hash[twice + 1000]) {
                    if (x != 0 || hash[1000] > 1)
                        return true;
                }
            }
        }

        return false;
    }
};