class Solution(object):
    def kthCharacter(self, k):
        """
        :type k: int
        :rtype: str
        """
        word = "a"
        first_w = 97
        last_w = 122
        
        while len(word) < k:
            for w in word:
                next_w = ord(w) + 1
                if last_w < next_w:
                    next_w = first_w
                word += chr(next_w)
        return word[k - 1]
                    
print("enter K: ")

k = int(input(), 10)

s = Solution()

print(s.kthCharacter(k))