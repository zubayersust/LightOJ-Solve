# Online Judge : LightOJ
# Problem No   : 1159
# Problem Name : Batman
# Author       : Zubayer Rahman
# Email        : zubayer.csesust@gmail.com
# Time Limit   : 5.000s
# CPU          : 0.0s
# Memory       : 0KB
# Algorithm    : Dynamic Programming (LCS)

import sys

MAX_LENGTH = 50
dp = [[[-1 for _ in range(MAX_LENGTH + 1)] for _ in range(MAX_LENGTH + 1)] for _ in range(MAX_LENGTH + 1)]


def LCS(s1, s2, s3, i, j, k):
    global dp

    if i == 0 or j == 0 or k == 0:
        return 0

    if dp[i][j][k] != -1:
        return dp[i][j][k]

    if s1[i - 1] == s2[j - 1] and s2[j - 1] == s3[k - 1]:
        dp[i][j][k] = 1 + LCS(s1, s2, s3, i - 1, j - 1, k - 1)
        return dp[i][j][k]

    dp[i][j][k] = max(
        LCS(s1, s2, s3, i - 1, j, k),
        LCS(s1, s2, s3, i, j - 1, k),
        LCS(s1, s2, s3, i, j, k - 1)
    )
    return dp[i][j][k]


def main():
    global dp

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
        s3 = inp.readline().strip()

        for i in range(len(s1) + 1):
            for j in range(len(s2) + 1):
                for k in range(len(s3) + 1):
                    dp[i][j][k] = -1

        lcs = LCS(s1, s2, s3, len(s1), len(s2), len(s3))

        out.write(f"Case {test_case}: {lcs}\n")

        test_case += 1


if __name__ == '__main__':
    main()
