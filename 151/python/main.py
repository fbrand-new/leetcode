class Solution:
    def reverseWords(self, s: str) -> str:
        list_of_words = s.split(" ")
        list_of_words = [x for x in list_of_words if x != ""]
        return " ".join(list_of_words[::-1]).strip()


if __name__ == "__main__":
    test_string = "the sky is blue"
    test_string2 = "  hello world  "
    test_string3 = "a good    example"
    sol = Solution()
    res = sol.reverseWords(test_string)
    res2 = sol.reverseWords(test_string2)
    res3 = sol.reverseWords(test_string3)
    print(res)
    print(res2)
    print(res3)
