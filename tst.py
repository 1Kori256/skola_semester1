import numpy as np
g = (1 + np.sqrt(5)) / 2

points = [
    [0, 0, 0, 1],
    [0, 0, 1, 0],
    [0, 1, 0, 0],
    [1, 0, 0, 0],

    [0.5, 0.5, 0.5, 0.5],

    [g/2, 1/2, 1/(2*g), 0],
    [g/2, 1/(2*g), 0, 1/2],
    [g/2, 0, 1/2, 1/(2*g)],
    [0, g/2, 1/(2*g), 1/2],
    [1/(2*g), g/2, 1/2, 0],
    [1/2, g/2, 0, 1/(2*g)],
    [0, 1/2, g/2, 1/(2*g)],
    [1/2, 1/(2*g), g/2, 0],
    [1/(2*g), 0, g/2, 1/2],
    [0, 1/(2*g), 1/2, g/2],
    [1/(2*g), 1/2, 0, g/2],
    [1/2, 0, 1/(2*g), g/2]
]

signs = [[1, 1, 1, 1],
         [1, 1, 1, -1],
         [1, 1, -1, 1],
         [1, -1, 1, 1],
         [-1, 1, 1, 1],
         [-1, -1, 1, 1],
         [-1, 1, -1, 1],
         [-1, 1, 1, -1],
         [1, -1, -1, 1],
         [1, -1, 1, -1],
         [1, 1, -1, -1],
         [-1, -1, -1, 1],
         [-1, -1, 1, -1],
         [-1, 1, -1, -1],
         [1, -1, -1, -1],
         [-1, -1, -1, -1]]

ans = set()
for point in points:
    for sign in signs:
        new_lst = [point[0] * sign[0], point[1] * sign[1], point[2] * sign[2], point[3] * sign[3]]
        ans.add(" ".join(map(str,new_lst)))

points = []
for point in ans:
    points.append(list(map(float, point.split(" "))))

print(points)
print(len(points))