class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        this->m_pData = pData;
    }

    // Implement an assignment operator
    Solution& operator=(const Solution &object) {
        char *p = NULL;
        if (object.m_pData) {
            p = new char[strlen(object.m_pData) + 1];
            strcpy(p, object.m_pData);
        }
        delete this->m_pData;
        this->m_pData = p;
        return *this;
    }
};
