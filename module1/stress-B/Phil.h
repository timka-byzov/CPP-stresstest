#pragma once

#include <iostream>
#include <stack>
#include <string>

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

std::string checkBracketSequence(const std::string &sequence) {
    std::stack<char> bracketStack;

    for (char bracket: sequence) {
        if (bracket == '(' || bracket == '[' || bracket == '{') {
            bracketStack.push(bracket);
        } else {
            if (bracketStack.empty() || !isMatching(bracketStack.top(), bracket)) {
                return std::to_string(bracketStack.size());
            }
            bracketStack.pop();
        }
    }

    return bracketStack.empty() ? "CORRECT" : std::to_string(bracketStack.size());
}
