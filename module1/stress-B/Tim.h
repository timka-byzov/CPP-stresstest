#pragma once

#include <bits/stdc++.h>
#include <algorithm>
#include <vector>

std::unordered_map<char, char> brackets{
        {'[', ']'},
        {'(', ')'},
        {'{', '}'},

};

std::string checkBrackets(std::string &seq) {
    std::stack<char> stack;


    for (int idx = 0; idx < seq.size(); ++idx) {
        if (brackets.find(seq[idx]) != brackets.end()) { // open bracket
            stack.push(seq[idx]);
        } else { // close bracket
            if (!stack.empty() && brackets[stack.top()] == seq[idx]) {
                stack.pop();
            } else {
                return std::to_string(idx);
            }
        }
    }

    return stack.empty() ? "CORRECT" : std::to_string(seq.size());
}
