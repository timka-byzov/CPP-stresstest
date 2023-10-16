#include <algorithm>
#include <string>

#include "solution1.h"
#include "solution2.h"
#include "solution3.h"


int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // generate random sequences of Coin objects and compare results of solution1 and solution2

    for (int i = 0; i < 100; ++i) {
        int n = std::rand() % 3 + 1;
        std::vector<solution1::Coin> coins1(n);
        std::vector<solution2::Coin> coins2(n);
        std::vector<solution3::Coin> coins3(n);

        for (int j = 0; j < n; ++j) {
            int64_t dist = std::rand() % 10;
            int64_t deadline = std::rand() % 10;
            coins1[j] = {deadline, dist};
            coins2[j] = {deadline, dist};
            coins3[j] = {deadline, dist};
        }


        std::vector<std::vector<int64_t>> dp(n, std::vector<int64_t>(n, -1));

        auto res1 = solution1::solve(n, coins1, dp);
        auto res2 = solution2::solve(n, coins2, dp);
        auto res3 = solution3::solve(n, coins3, dp);

        if (res1 != res2 || res1 != res3) {
            std::cout << "Error: " << res1 << " != " << res2 << std::endl;
            std::cout << "Coins: " << std::endl;
            for (int j = 0; j < n; ++j) {
                std::cout << coins1[j].deadline << " " << coins1[j].dist << std::endl;
            }

            std::cout << "Solution1: " << res1 << std::endl;
            std::cout << "Solution2: " << res2 << std::endl;
            std::cout << "Solution3: " << res3 << std::endl;

            return 0;

        }

        std::cout << "Test " << i << " passed" << std::endl;
    }
}