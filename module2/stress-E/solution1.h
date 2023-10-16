#include <bits/stdc++.h>
#include <algorithm>
#include <utility>
#include <vector>
#include <limits>

namespace solution1{
    struct Coin {
        int64_t deadline;
        int64_t dist;
    };

    int64_t INF = std::numeric_limits<int>::max();

    std::vector<Coin> coins;
    std::vector<std::vector<int64_t>> dp;

    int64_t getMinDist(const Coin &cstart, const Coin &cend, int64_t prev_time) {
        if (cend.deadline - prev_time - std::abs(cend.dist - cstart.dist) >= 0)
            return std::abs(cend.dist - cstart.dist);
        else
            return INF;
    }

    int64_t F(int i, int j) {
        if (i == j) {
            dp[i][j] = 0;
        } else if (dp[i][j] == -1) {
            if (j > i) {
                int64_t i_to_j_min_1 = F(i, j - 1);
                int64_t j_min_1_to_i = F(j - 1, i);


                dp[i][j] = std::min(i_to_j_min_1 + getMinDist(coins[j - 1], coins[j], i_to_j_min_1),
                                    j_min_1_to_i + getMinDist(coins[i], coins[j], j_min_1_to_i));

                int64_t i_plus_1_to_j = F(i + 1, j);
                int64_t j_to_i_plus_1 = F(j, i + 1);
                dp[j][i] = std::min(i_plus_1_to_j + getMinDist(coins[j], coins[i], i_plus_1_to_j),
                                    j_to_i_plus_1 + getMinDist(coins[i + 1], coins[i], j_to_i_plus_1));
            }
        }
        return dp[i][j];
    }


    int64_t solve(int n, std::vector<Coin> coins1, std::vector<std::vector<int64_t>> dp1) {
        coins = std::move(coins1);
        dp = std::move(dp1);

        std::sort(coins.begin(), coins.end(), [](const Coin &a, const Coin &b) {
            return a.dist < b.dist;
        });

        auto res =  F(0, n - 1);

        if (res >= INF){
            return -1;
        } else {
            return res;
        }

    }

}
