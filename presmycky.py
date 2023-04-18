N = int(input())
words = []
anagrams = {}
for i in range(N):
    words.append(input())
for i, word in enumerate(words):
    sorted_anagram = "".join(sorted(word))
    if sorted_anagram in anagrams:
        anagrams[sorted_anagram].append(i)
    else:
        anagrams[sorted_anagram] = [i]

M = int(input())
for i in range(M):
    test_word = input()
    sorted_test_word = "".join(sorted(test_word))
    if sorted_test_word in anagrams:
        print(" ".join(sorted([words[j] for j in anagrams[sorted_test_word]])))
    else:
        print("")