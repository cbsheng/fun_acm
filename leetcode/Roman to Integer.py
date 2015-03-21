class Solution:
    # @return an integer
    def romanToInt(self, s):
        roman = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        if len(s) == 1:
            return roman[s[0]]
        else:
            l = list(s)
            old = l.pop()
            integer = roman[old]
            while l:
                new = l.pop()
                if roman[old] > roman[new]:
                    integer -= roman[new]
                elif roman[old] > roman[new]:
                    integer += roman[new]
                else:
                    integer += roman[new]
                old = new
            return integer 
            