class Solution:
    # @param digits, a list of integer digits
    # @return a list of integer digits
    def plusOne(self, digits):
        if not digits:
            return None
        digits.reverse()
        carry = 1
        i = 0
        while carry:
            if i >= len(digits):
                digits.append(carry)
                carry = 0
            temp = digits[i] + carry
            if temp >= 10:
                digits[i], carry = temp % 10, temp / 10
            else:
                digits[i] = temp
                carry = 0
            i += 1
        digits.reverse()
        return digits