#include <algorithm>
#include "Phil.h"
#include "Tim.h"
#include "Tim2.h"
#include <string>


int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    // generate rqndom sequences of length 1..6 with elements from -10..10 and compare results
    for (int test_num = 1; test_num < 1000; test_num++){
        int n = std::rand() % 6 + 1;
        std::vector<int> a(n);
        for (int i = 0; i < n; i++){
            a[i] = std::rand() % 21 - 10;
        }
        int m = std::rand() % 6 + 1;
        std::vector<int> b(m);
        for (int i = 0; i < m; i++){
            b[i] = std::rand() % 21 - 10;
        }
        int res1 = Tim::solve(a, b);
        int res2 = Tim2::longestCommonSubsequence(a, b);
        if (res1 != res2){
            std::cout << "Test #" << test_num << " failed" << std::endl;
            std::cout << "a = ";
            for (int i = 0; i < n; i++){
                std::cout << a[i] << " ";
            }
            std::cout << std::endl;
            std::cout << "b = ";
            for (int i = 0; i < m; i++){
                std::cout << b[i] << " ";
            }
            std::cout << std::endl;
            std::cout << "Tim1: " << res1 << std::endl;
            std::cout << "Tim2: " << res2 << std::endl;
            return 0;
        }

    }

}