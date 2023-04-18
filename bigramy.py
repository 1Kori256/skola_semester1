import io
with io.open("vstup.txt",'r',encoding='utf8') as f:
    text = f.read()

lst = {}

prevchar = ""
for char in text:
    if char.isalpha():
        new_double = prevchar + char.lower()
        if len(new_double) == 2:
            if new_double in lst:
                lst[new_double] += 1
            else:
                lst[new_double] = 1
        prevchar = char.lower()
    else:
        prevchar = ""

ans = []
for k, v in lst.items():
    ans.append([k, v])

ans = sorted(ans, key=lambda x: (-x[1], x[0]))

text = ""
for i in ans:
    text += i[0] + " " + str(i[1]) + "\n"

with io.open("vystup.txt",'w',encoding='utf8') as f:
    f.write(text)
