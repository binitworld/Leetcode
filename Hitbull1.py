# /*You want to plant trees in a square lawn of size n×n
#  whose corners have Cartesian coordinates (0,0)
# , (n,0)
# , (0,n)
# , and (n,n)
# . Trees can only be planted at locations with integer coordinates. Every tree will grow roots within a disk of radius r
#  centered at the location where the tree was planted; such disks must be fully contained in the lawn (possibly touching the boundary of the lawn) and can only intersect each other on their boundaries.

# Find a configuration that maximizes the number of trees.

# Input
# The first and only line contains an integer n
#  (1≤n≤20
# ) and a real number r
#  (0<r≤n/2
# ) — the length of the sides of the lawn, and the radius of the disks where each tree will grow roots. The real number r
#  is given in decimal notation with at least 1
#  and at most 3
#  digits after the decimal point.

# Output
# In the first line, print the maximum number m
#  of trees that can be planted.

# In the next m
#  lines, print a configuration that maximizes the number of trees. Specifically, in the (i+1)
# -th line, print two integers x
#  and y
#  — the coordinates of the location where the i
# -th tree should be planted. You can print the trees in any order.

# If there are multiple solutions, print any of them.

# */

import math

def plant_trees(n, r):
    if r >= n / 2:
        return [(n // 2, n // 2)]

    max_trees = 0
    best_config = []

    for i in range(n + 1):
        for j in range(n + 1):
            trees_planted = 0
            for x in range(1, n + 1):
                for y in range(1, n + 1):
                    if (x - i) ** 2 + (y - j) ** 2 <= r ** 2:
                        trees_planted += 1
            if trees_planted > max_trees:
                max_trees = trees_planted
                best_config = [(i, j)]

    return max_trees, best_config

# Input
n, r = map(float, input().split())

# Calculate maximum number of trees and the configuration
max_trees, config = plant_trees(int(n), r)

# Output
print(max_trees)
for tree in config:
    print(*tree)
