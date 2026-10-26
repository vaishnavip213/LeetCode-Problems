class Solution {
public:
    int calculateScore(int a, int b) {
        bitset<32>binary1(a);
        bitset<32>binary2(b);

        int s1 = binary1.count();
        int s2 = binary2.count();

        if(s1>=s2){return s1*s2; }
        return int(s2/s1);
    }
};