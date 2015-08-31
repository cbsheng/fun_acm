class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        map<int, int> m;
        return fibonacciHelper(n, m);
    }
    
    int fibonacciHelper(int n, map<int, int> &m) {
        if (m.count(n) == 1) return m[n];
        if (n == 1) m[n] = 0;
        else if (n == 2) m[n] = 1;
        else {
            int res = fibonacciHelper(n - 1, m) + fibonacciHelper(n - 2, m);
            m[n] = res;
        }
        return m[n];
    }
};

