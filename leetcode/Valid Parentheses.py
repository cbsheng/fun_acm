class Solution:
    # @return a boolean
    def isValid(self, s):
        d ={'(':')', '[':']', '{':'}'}
        stack = []
        for elem in s:
            if elem in '([{':
                stack.append(elem)
            else:
                if not stack or d[stack.pop()] != elem:
                    return False
        return True if not stack else False