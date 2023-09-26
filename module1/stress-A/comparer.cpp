#include <algorithm>
#include "Phil.h"
#include "Tim.h"
#include <string>


int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    // generate rqndom sequences of length 1..6 with elements from -10..10 and compare results
    for (int test_num = 1; test_num < 1000; test_num++){
        int seq_len = rand() % 10 + 1;

        std::vector<int> seq;
        for (int i = 0; i < seq_len; ++i){
            seq.push_back(rand() % 20 - 10);
        }

        auto tim_ans = solve_Tim(seq, seq_len);
        auto phil_ans = solve_Phil(seq, seq_len);

        if (phil_ans != tim_ans){
            std::cout << seq_len << std::endl;

            for (auto &el : seq){
                std::cout << el << " ";
            }std::cout << std::endl;

            std::cout << std::endl;
            std::cout << "Phil's ans: " << std::endl;
            for (auto &el : phil_ans){
                std::cout << el << " ";
            }std::cout << std::endl;

            std::cout << "Tim's ans: " << std::endl;
            for (auto &el : tim_ans){
                std::cout << el << " ";
            }std::cout << std::endl;
            return 0;
        }

    }

}