class Solution(object):
    def kthCharacter(self, k):
        """
        :type k: int
        :rtype: str
        """
        word = "a"
        
        while len(word) < k:
            for w in word:
                word += chr((ord(w) - ord('a') + 1) % 26 + ord('a'))
        return word[k-1]
                    
print("enter K: ")

k = int(input(), 10)

s = Solution()

print(s.kthCharacter(k))