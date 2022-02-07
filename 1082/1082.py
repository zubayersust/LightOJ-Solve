# Online Judge : LightOJ
# Problem No   : 1082
# Problem Name : Array Queries
# Author       : Zubayer Rahman
# Email        : zubayer.csesust@gmail.com
# Time Limit   : 10.000s
# CPU          : 6.953s
# Memory       : 21840KB
# Algorithm    : Segment Tree

import sys

MAX_ELEMENTS = 100010

data = [0] * MAX_ELEMENTS
Tree = [0] * MAX_ELEMENTS * 3


def init(node, a, b):
    global data
    global Tree

    if a == b:
        Tree[node] = data[a]
        return

    left = node * 2
    right = node * 2 + 1
    mid = int((a + b) / 2)

    init(left, a, mid)
    init(right, mid + 1, b)

    Tree[node] = min(Tree[left], Tree[right])


def query(node, a, b, i, j):
    if i > b or j < a:
        return 100010

    if a >= i and b <= j:
        return Tree[node]

    left = node * 2
    right = node * 2 + 1
    mid = int((a + b) / 2)

    return min(
        query(left, a, mid, i, j),
        query(right, mid + 1, b, i, j)
    )


def main():
    inp = sys.stdin
    out = sys.stdout

    try:
        inp = open("input.txt", "r")
    except:
        pass

    test_case = 1
    T = int(inp.readline().strip())

    global data

    while test_case <= T:
        inp.readline().strip()

        n, q = map(int, inp.readline().strip().split())
        data = list(map(int, inp.readline().strip().split()))
        data.insert(0, -1)

        init(1, 1, n)

        out.write(f"Case {test_case}:\n")

        for _ in range(q):
            i, j = map(int, inp.readline().strip().split())
            out.write(f"{query(1, 1, n, i, j)}\n")

        test_case += 1


if __name__ == '__main__':
    main()
