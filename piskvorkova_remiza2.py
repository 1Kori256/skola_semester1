R, S = list(map(int, input().split()))

pattern = ["XOXOXO",
           "OXOXOX",
           "OXOXOX",
           "XOXOXO"]

for i in range(R):
    print((S // len(pattern[0])) * pattern[i % len(pattern)] + pattern[i % len(pattern)][:(S % len(pattern[0]))])