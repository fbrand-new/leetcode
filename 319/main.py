class Solution:
    def vanillaBulbSwitch(self,n:int) -> int:
        b = [0 for i in range(n)]
        k = 1
        while k <= n:
            for i in range(k-1,n,k):
                b[i] = (b[i]+1)%2
            k = k + 1

        return sum(b)

    def bulbSwitch(self,n:int) -> int:


if __name__ == "__main__":
    s = Solution()
    print(s.bulbSwitch(3))
