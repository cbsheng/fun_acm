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
        if (&object != this) {
            delete []m_pData;
            m_pData = NULL;
            if (object.m_pData) {
                m_pData = new char[strlen(object.m_pData) + 1];
                strcpy(m_pData, object.m_pData);
            }
        }
        return *this;
    }
};
