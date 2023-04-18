import random
R, S = list(map(int, input().split()))

pattern = ["OOOOX",
           "OXXOX",
           "OXXOX",
           "OOOOX",
           "XXXXO"]

for i in range(R):
    print((S // 5) * pattern[i % 5] + pattern[i % 5][:(S % 5)])