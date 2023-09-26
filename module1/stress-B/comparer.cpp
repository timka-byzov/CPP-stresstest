#include <algorithm>
#include "Phil.h"
#include "Tim.h"
#include <string>


int main() {
    //generate random string brackets sequences
    std::vector<char> brackets = {'(', ')', '[', ']', '{', '}'};
    std::vector<std::string> seqs;
    for (int i = 0; i < 100; ++i){
        std::string seq = "";
        int seq_len = rand() % 10 + 1;
        for (int j = 0; j < seq_len; ++j){
            int bracket_idx = rand() % brackets.size();
            seq += brackets[bracket_idx];
        }
        seqs.push_back(seq);
    }

    //test Phil's solution
    for (auto &seq : seqs){
        auto phil_ans = checkBracketSequence(seq);
        auto tim_ans = checkBrackets(seq);
        if (phil_ans != tim_ans){
            std::cout << "Solution is wrong for seq: " << seq << std::endl;
            std::cout << "Phil's ans: " << phil_ans << std::endl;
            std::cout << "Tim's ans: " << tim_ans << std::endl;
            std::cout << std::endl;
            return 0;
        }
    }

}