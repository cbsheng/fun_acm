class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        if (s.size() == 0)
            return s;
        
        reverse(s, 0, s.size() - 1);
        int wbegin, wend;
        wbegin = wend = 0;
        while (wend < s.size()) {
            if (s[wbegin] == ' ') {
                wbegin++;
                wend++;
                continue;
            }
            if (s[wend] == ' ') {
                reverse(s, wbegin, wend - 1);
                wend++;
                wbegin = wend;
            }
            else {
                wend++;
            }
        }
        if (wbegin != wend)
            reverse(s, wbegin, wend - 1);
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end()); 
        return s;
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
