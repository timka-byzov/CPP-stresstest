#include <iostream>
#include <vector>
#include <algorithm>

struct Subsequence {
    std::vector<int> sequence;
    int length = 0;
    std::vector<int> indices;
};

Subsequence AlternatingSubsequence(std::vector<int> &arr, int totalNumber) {

    std::vector<std::vector<Subsequence>> dp(totalNumber, std::vector<Subsequence>(2));

    for (int i = 0; i < totalNumber; ++i) {
        dp[i][0].sequence.push_back(arr[i]);
        dp[i][0].length = 1;
        dp[i][0].indices.push_back(i);
        dp[i][1].sequence.push_back(arr[i]);
        dp[i][1].length = 1;
        dp[i][1].indices.push_back(i);
    }

    std::vector<Subsequence> subsequences;

    for (int irod = 1; irod < totalNumber; ++irod) {
        for (int jabroni = 0; jabroni < irod; ++jabroni) {
            if (arr[jabroni] < arr[irod] && dp[irod][0].length < dp[jabroni][1].length + 1) {
                dp[irod][0].sequence = dp[jabroni][1].sequence;
                dp[irod][0].sequence.push_back(arr[irod]);
                dp[irod][0].length = dp[jabroni][1].length + 1;
                dp[irod][0].indices = dp[jabroni][1].indices;
                dp[irod][0].indices.push_back(irod);
            }

            if (arr[jabroni] > arr[irod] && dp[irod][1].length < dp[jabroni][0].length + 1) {
                dp[irod][1].sequence = dp[jabroni][0].sequence;
                dp[irod][1].sequence.push_back(arr[irod]);
                dp[irod][1].length = dp[jabroni][0].length + 1;
                dp[irod][1].indices = dp[jabroni][0].indices;
                dp[irod][1].indices.push_back(irod);
            }
        }

        int maxLength = std::max(dp[irod][0].length, dp[irod][1].length);
        if (maxLength > 1) {
            if (dp[irod][0].length == maxLength) {
                subsequences.push_back(dp[irod][0]);
            }
            if (dp[irod][1].length == maxLength) {
                subsequences.push_back(dp[irod][1]);
            }
        }
    }

    Subsequence smallestSubsequence;
    smallestSubsequence.length = 0;
    for (const Subsequence &subsequence: subsequences) {
        if (subsequence.length > smallestSubsequence.length ||
            (subsequence.length == smallestSubsequence.length &&
             subsequence.indices < smallestSubsequence.indices)) {
            smallestSubsequence = subsequence;
        }
    }

    return smallestSubsequence;
}

std::vector<int> removeNeighboringDuplicates(const std::vector<int> &sequence) {
    std::vector<int> result;
    if (sequence.empty()) {
        return result;
    }

    result.push_back(sequence[0]);

    for (size_t i = 1; i < sequence.size(); ++i) {
        if (sequence[i] != sequence[i - 1]) {
            result.push_back(sequence[i]);
        }
    }

    return result;
}


std::vector<int> solve_Phil(std::vector<int> arr, int totalNumber) {

    arr = removeNeighboringDuplicates(arr);
    totalNumber = arr.size();

    if (totalNumber == 1) {
        return std::vector<int>{arr[0]};
    }
    Subsequence result = AlternatingSubsequence(arr, totalNumber);
    return result.sequence;
}


