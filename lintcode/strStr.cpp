class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        if (NULL == source || NULL == target) return -1;
        int i, j;
        for (i = 0; i < strlen(source) - strlen(target) + 1; ++i) {
            for (j = 0; j < strlen(target); ++j) {
                if (source[i+j] != target[j]) break;
            }
            if (j == strlen(target)) return i;
        }
        return -1;
    }
};