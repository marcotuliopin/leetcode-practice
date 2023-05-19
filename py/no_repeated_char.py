class Solution(object):
    def solution1(self, s):
        """
        :type s: str
        :rtype: int
        """
        biggest = 0
        for i in range(len(s)):
            if (len(s) - i) < biggest:
                return
            a = {s[i]}
            num = 1
            for j in range(i + 1, len(s)):
                if s[j] in a:
                    break
                else:
                    num += 1
                    a.add(s[j])
            if num > biggest:
                biggest = num
        return biggest

    def solution2(self, s):
        biggest = 0
        l = 0
        a = set()
        for i in range(len(s)):
            # if find a duplicate
            while s[i] in a:
                # cut the substring until there is no repeated characters
                a.remove(s[l])
                l += 1
            # continue building a substring
            a.add(s[i])
            # compute the maximum length substring
            biggest = max(biggest, i - l + 1)
        return biggest
