class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        if (length == 0) return 0;
        int new_length = length;
        for (int i = 0; i < length; ++i) {
            if (string[i] == ' ') {
                new_length += 2;
            }
        }
        string[new_length--] = '\0';
        
        for (int i = length - 1; i >= 0; --i) {
            if (string[i] == ' ') {
                string[new_length--] = '0';
                string[new_length--] = '2';
                string[new_length--] = '%';
            } else {
                string[new_length--] = string[i];
            }
        }
        
        return strlen(string);
    }
};  
