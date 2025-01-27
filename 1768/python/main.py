# You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.
#
# Return the merged string.


class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        return self.merge_noob(word1, word2)

    def merge_noob(self, word1: str, word2: str):
        new_word = []
        if len(word1) > len(word2):
            for i in range(len(word2)):
                new_word.append(word1[i])
                new_word.append(word2[i])
            new_word.append(word1[len(word2) :])
        elif len(word2) >= len(word1):
            for i in range(len(word1)):
                new_word.append(word1[i])
                new_word.append(word2[i])
            new_word.append(word2[len(word1) :])

        return "".join(new_word)
