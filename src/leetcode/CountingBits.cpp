class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        for (int i = 0; i <= num; ++i) {
            res.push_back(getCounts(i));
        }
        
        return res;
    }
    
    int getCounts(int num) {
        int count = 0;
        
        while (num) {
            int bit = num % 2;
            if (bit == 1) {
                count++;
            }
            num = num / 2;
        }
        
        return count;
    }
};



public int[] countBits(int num) {
    int[] f = new int[num + 1];
    for (int i=1; i<=num; i++) f[i] = f[i >> 1] + (i & 1);
    return f;
}