class Solution:
    def largestInteger(self, num: int) -> int:
        
        digits = [int(i) for i in str(num)]
        odd_nums = []
        odd_pos = []
        even_nums = []
        even_pos = []
        for i,d in enumerate(digits):
            if d%2 == 0:
                even_nums.append(d)
                even_pos.append(i)
            else:
                odd_nums.append(d)
                odd_pos.append(i)

        even_nums = sorted(even_nums, reverse=True)
        odd_nums = sorted(odd_nums, reverse=True)

        even_map = {k:v for k,v in zip(even_pos,even_nums)}
        odd_map = {k:v for k,v in zip(odd_pos,odd_nums)}

        all_numbers_dict = dict(sorted((even_map | odd_map).items())) # Merge two dicts

        s = [str(i) for i in all_numbers_dict.values()]

        return int("".join(s))

        



if __name__ == "__main__":
    
    sol = Solution()
    num = 1234
    sol.largestInteger(num)

    