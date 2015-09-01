class Solution {
public:
    Solution() {}
    Solution(const Solution &s) {}
    Solution& operator=(const Solution &s) {}
    /**
     * @return: The same instance of this class every time
     */
    static Solution* getInstance() {
        static Solution instance;
        return &instance;
    }
};
