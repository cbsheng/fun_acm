class Solution {
public:
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    void rotateString(string &str,int offset){
        if (str.size() == 0)
            return;
        int a = offset % str.size();
        reverse(str, 0, str.size() - a - 1);
        reverse(str, str.size() - a, str.size() - 1);
        reverse(str, 0, str.size() - 1);
    }
    
    void reverse(string &s, int begin, int end) {
        char tmp;
        while (begin < end) {
            tmp = s[begin];
            s[begin] = s[end];
            s[end] = tmp;
            begin++;
            end--;
        }
    }
};

