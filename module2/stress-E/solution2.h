#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <limits>

#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:16777216")

namespace solution2 {
    struct Coin {
        int64_t deadline;
        int64_t dist;

        bool operator<(const Coin &other) const {
            if (dist == other.dist)
                return deadline < other.deadline;
            return dist < other.dist;
        }
    };

    int64_t INF = std::numeric_limits<int>::max();


    int64_t getMinDist(const Coin &cstart, const Coin &cend, int64_t prev_time) {
        if (cend.deadline - prev_time - std::abs(cend.dist - cstart.dist) >= 0)
            return std::abs(cend.dist - cstart.dist);
        else
            return INF;
    }

    int64_t truncateINF(int64_t x) {
        if (x > INF)
            return INF;
        return x;
    }

    void FillDP(std::vector<Coin> &coins, std::vector<std::vector<int64_t>> &dp) {
        int n = static_cast<int>(coins.size());
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i < n - len + 1; ++i) {
                int j = i + len - 1;
                if (i == j) {
                    dp[i][j] = 0;
                } else {

                    dp[i][j] = std::min(truncateINF(dp[i][j - 1] + getMinDist(coins[j - 1], coins[j], dp[i][j - 1])),
                                        truncateINF(dp[j - 1][i] + getMinDist(coins[i], coins[j], dp[j - 1][i])));


                    dp[j][i] = std::min(truncateINF(dp[i + 1][j] + getMinDist(coins[j], coins[i], dp[i + 1][j])),
                                        truncateINF(dp[j][i + 1] + getMinDist(coins[i + 1], coins[i], dp[j][i + 1])));

                }
            }
        }
    }


    int64_t solve(int n, std::vector<Coin> coins, std::vector<std::vector<int64_t>> dp) {

        std::sort(coins.begin(), coins.end());

        FillDP(coins, dp);

        if (dp[0][n - 1] >= INF) {
            return -1;
        }

        return dp[0][n - 1];

    }
}