#include <bits/stdc++.h>


namespace Tim {


    int solve(std::vector<int> a, std::vector<int> b) {
        std::vector<int> b_counts((int) b.size(), 0);

//    std::vector<int>dp((int)a.size());

        for (int num: a) {
            int max_length = 0;
            for (int b_idx = 0; b_idx < (int) b.size(); ++b_idx) {

                int prev_max_length = max_length;
                max_length = std::max(max_length, b_counts[b_idx]);

                if (b[b_idx] == num) {
                    b_counts[b_idx] = prev_max_length + 1;
                }
            }
        }

        int res = b_counts[0];
        for (int i_idx = 1; i_idx < b.size(); ++i_idx) {
            res = std::max(res, b_counts[i_idx]);
        }

        return res;
    }

}
