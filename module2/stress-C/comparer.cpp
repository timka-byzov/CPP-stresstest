#include <algorithm>
#include <string>

#include "fast.h"
#include "slow.h"


int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // generate 1..5 points (type Point) with coordinates from -10...10 and compare results of fast and slow solutions

    for (int test_num = 1; test_num < 1000; test_num++) {
        int n = std::rand() % 5 + 1;
        std::vector<Point> points(n);
        for (int i = 0; i < n; i++) {
            points[i].x = std::rand() % 21 - 10;
            points[i].y = std::rand() % 21 - 10;
        }
        int k = std::rand() % n + 1;
        long double res1 = fast::findMinRadius(points, k);
        long double res2 = slow::findMinRadius(points, k);
        if (std::abs(res1 - res2) > 1e-3) {
            std::cout << "Test #" << test_num << " failed" << std::endl;
            std::cout << "points = ";
            for (int i = 0; i < n; i++) {
                std::cout << "(" << points[i].x << ", " << points[i].y << ") ";
            }
            std::cout << std::endl;
            std::cout << "k = " << k << std::endl;
            std::cout << "fast: " << res1 << std::endl;
            std::cout << "slow: " << res2 << std::endl;
            return 0;
        }
    }
}
