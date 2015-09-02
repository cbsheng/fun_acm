class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        int a = 1, res = 0;
        for (int i = 0; i < (sizeof(num) * 8); ++i) {
            if ((num & a) == a)
                res++;
            a <<= 1;
        }
        return res;
    }
};

//只循环1的个数那么多次
class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        int cnt = 0, n = num;
        while (n) {
            cnt++;
            n = (n - 1) & n;
        }
        return cnt;
    }
};
