#include <bits/stdc++.h>

#include <algorithm>
#include <vector>
#include <limits>

namespace Tim2{
    std::vector<std::vector<int>> memo;

    std::vector<int> findLCS(const std::vector<int>& x, const std::vector<int>& y, int i, int j) {
        if (i == 0 || j == 0) {
            return {};
        } else if (x[i - 1] == y[j - 1]) {
            std::vector<int> lcs = findLCS(x, y, i - 1, j - 1);
            lcs.push_back(x[i - 1]);
            return lcs;
        } else {
            std::vector<int> lcs1 = findLCS(x, y, i - 1, j);
            std::vector<int> lcs2 = findLCS(x, y, i, j - 1);
            return (lcs1.size() > lcs2.size()) ? lcs1 : lcs2;
        }
    }

   int longestCommonSubsequence(const std::vector<int>& x, const std::vector<int>& y) {
        int m = x.size();
        int n = y.size();
        memo.assign(m + 1, std::vector<int>(n + 1, -1));

        return findLCS(x, y, m, n).size();
    }

}

