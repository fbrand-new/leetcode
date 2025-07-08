class Solution:

    def conv(self, nu: list):
        return [str(i) for i in nu]
        
    def splitNum(self, num: int) -> int:
        # We need to split the digits so that lowest goes to num1, second lowest to num2,
        # third lowest to num1 and so on, to obtain the smallest possible permutation and sum
        digits = [int(i) for i in str(num)]
        digits = sorted(digits)
        num1 = []
        num2 = []
        for i in range(0,len(digits),2):
            num1.append(digits[i])
            if(i+1 == len(digits)):
                break
            num2.append(digits[i+1])

        return int("".join(self.conv(num1))) + int("".join(self.conv(num2)))
    
if __name__ == "__main__":

    num = 4325
    sol = Solution()
    print(sol.splitNum(num))

