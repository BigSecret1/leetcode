class Solution {
public:
    int minBitFlips(int start, int goal) {
        int answer = 0;
        while(start > 0 || goal  > 0) {
            if((start & 1) != (goal & 1)) {
                answer++;
            }
            start /= 2;
            goal /= 2;
        }
        return answer;
    }
};
