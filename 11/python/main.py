class Solution:
    def maxArea(self, height: list[int]) -> int:
        # 1. Initial max area is given by the extremes as borders
        left = 0
        right = len(height) - 1
        idxs = [left,right]
        borders = [height[left],height[right]]
        min_height = min(borders)
        min_idx = idxs[borders.index(min_height)]
        max = (right-left)*min_height

        # 2. Keep looping on the minimum side until you reach a higher 
        while right>left:
            if min_idx == 0:
                left += 1
                if height[left] > borders[0]:
                    borders[0] = height[left]
            elif min_idx == 1:
                right -= 1
                if height[right] > borders[1]:
                    borders[1] = height[right]
            
            idxs = [left,right]
            min_height = min(borders)
            area = min_height*(right-left)
            min_idx = borders.index(min_height)
            if area > max:
                max = area

        return max

if __name__ == "__main__":
    height = [1,8,6,2,5,4,8,3,7]
    sol = Solution()
    print(f"Answer: {sol.maxArea(height)}")