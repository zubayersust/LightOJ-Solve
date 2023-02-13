# Online Judge : LightOJ
# Problem No   : 1110
# Problem Name : An Easy LCS
# Author       : Zubayer Rahman
# Email        : zubayer.csesust@gmail.com
# Time Limit   : 5.000s
# CPU          : 0.915s
# Memory       : 3488KB
# Algorithm    : Dynamic Programming (LCS)

import sys


def minim(s1, s2) -> str:
    if len(s1) > len(s2):
        return s1
    if len(s1) < len(s2):
        return s2

    for i in range(len(s1)):
        if s1[i] < s2[i]:
            return s1
        if s1[i] > s2[i]:
            return s2

    return s1


# def LCS(s1, s2):
#     n = len(s1)
#     m = len(s2)
#
#     lcs = [["" for _ in range(m + 1)] for _ in range(n + 1)]
#
#     for i in reversed(range(n)):
#         for j in reversed(range(m)):
#             if i == n or j == m:
#                 lcs[i][j] = ""
#                 continue
#
#             if s1[i] == s2[j]:
#                 lcs[i][j] = s1[i] + lcs[i + 1][j + 1]
#                 continue
#
#             lcs[i][j] = minim(lcs[i][j + 1], lcs[i + 1][j])
#
#     return lcs[0][0]


# space optimized version
def LCS(s1, s2):
    n = len(s1)
    m = len(s2)

    binary_index = bool

    lcs = [["" for _ in range(m + 1)] for _ in range(2)]
    for i in reversed(range(n)):
        binary_index = i & 1

        for j in reversed(range(m)):
            if i == n or j == m:
                lcs[binary_index][j] = ""
                continue

            if s1[i] == s2[j]:
                lcs[binary_index][j] = s1[i] + lcs[1 - binary_index][j + 1]
                continue

            lcs[binary_index][j] = minim(lcs[binary_index][j + 1], lcs[1 - binary_index][j])

            print(lcs)

    return lcs[binary_index][0]


def main():
    inp = sys.stdin
    out = sys.stdout

    try:
        inp = open("input.txt", "r")
    except:
        pass

    test_case = 1
    T = int(inp.readline().strip())

    while test_case <= T:
        inp.readline().strip()

        s1 = inp.readline().strip()
        s2 = inp.readline().strip()

        lcs = LCS(s1, s2)
        if lcs:
            out.write(f"Case {test_case}: {lcs}\n")
        else:
            out.write(f"Case {test_case}: :(\n")

        test_case += 1


if __name__ == '__main__':
    main()
