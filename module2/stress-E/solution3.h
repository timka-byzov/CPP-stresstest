#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>

namespace solution3 {
    struct Coin {
        int64_t deadline;
        int64_t dist;
    };

    int64_t INF = std::numeric_limits<int>::max();

    int64_t dist(const Coin &cstart, const Coin &cend, int64_t prev_time) {
        if (cend.deadline - prev_time - std::abs(cend.dist - cstart.dist) >= 0)
            return std::abs(cend.dist - cstart.dist);
        else
            return INF;
    }

    int64_t solve(int n, std::vector<Coin> coins, std::vector<std::vector<int64_t>> dp) {
        int64_t min_time = INF;

        std::vector<int> order(n);
        for (int i = 0; i < n; ++i) {
            order[i] = i;
        }

        do {
            int64_t time = 0;
            for (int i = 1; i < n; ++i) {
                time += dist(coins[order[i - 1]], coins[order[i]], time);
            }

            min_time = std::min(min_time, time);
        } while (std::next_permutation(order.begin(), order.end()));


        if (min_time >= INF)
            return -1;
        else
            return min_time;

    }

}

