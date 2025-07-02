
import copy

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max = 0 
        visited = []
        counter = 0
        for c in s:
            if c not in visited:
                counter += 1
                visited.append(c)
            else:
                if counter > max:
                    max = counter

                for i in range(len(visited)):
                    current_char = visited.pop(0)
                    counter -= 1
                    # print(f"c is {c}")
                    # print(f"current char is {current_char}")
                    if c == current_char:
                        break

                visited.append(c)
                # print(visited)
                counter += 1

        if counter>max:
            max = counter

        return max

if __name__ == "__main__":

    sol = Solution()

    s = "abcabcbb"
    print(sol.lengthOfLongestSubstring(s))

    s2 = "pwwkew"
    print(f"s2 is {sol.lengthOfLongestSubstring(s2)}")

    s3 = "dvdf"
    print(f"s3 is {sol.lengthOfLongestSubstring(s3)}")