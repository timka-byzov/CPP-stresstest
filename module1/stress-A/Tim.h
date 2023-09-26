#include <bits/stdc++.h>


#include <algorithm>
#include <vector>

struct DP {

    std::vector<int> up, down;
    int size;

    explicit DP(int size) {
        up.resize(size, 0);
        down.resize(size, 0);
        this->size = size;
    }
};

struct Prev {

    std::vector<int> up, down;

    explicit Prev(int size) {
        up.resize(size, -1);
        down.resize(size, -1);
    }

};

// Есть два массива ДП, up[i] -- макс. длина чередующейся подпоследовательности из первых i элементов, такой,
// что последний элемент был больше предыдущего (последовательность идёт вверх); down[i] -- наоборот вниз.
// up[i] считается на основе down и наоборот
// Соответственно для up есть массив down, а для down -- up, это нужно для восстановления ответа.
// При чём предок выбирается так, чтобы удовлетворять условию о минимальности индексов
void fill_dp_and_prev(DP &dp, Prev &prev, std::vector<int> &sequence) {

    for (int dp_idx = 0; dp_idx < dp.size; ++dp_idx) {
        dp.up[dp_idx] = 1;
        dp.down[dp_idx] = 1;

        int prev_up_idx = 0, prev_down_idx = 0;

        for (int candidate_idx = 0; candidate_idx < dp_idx; ++candidate_idx) {
            if (sequence[candidate_idx] > sequence[dp_idx]) {
                if (1 + dp.up[candidate_idx] > dp.down[dp_idx] ||
                    1 + dp.up[candidate_idx] == dp.down[dp_idx] && prev.down[candidate_idx] < prev_down_idx) {
                    dp.down[dp_idx] = 1 + dp.up[candidate_idx];
                    prev.up[dp_idx] = candidate_idx;
                    prev_down_idx = prev.down[candidate_idx];
                }
            }

            if (sequence[candidate_idx] < sequence[dp_idx]) {
                if (1 + dp.down[candidate_idx] > dp.up[dp_idx] ||
                    1 + dp.down[candidate_idx] == dp.up[dp_idx] && prev.up[candidate_idx] < prev_up_idx) {
                    dp.up[dp_idx] = 1 + dp.down[candidate_idx];
                    prev.down[dp_idx] = candidate_idx;
                    prev_up_idx = prev.up[candidate_idx];
                }
            }
        }
    }
}


int get_max_subsequence_length(DP &dp) {
    int max_length = 0;
    for (int idx = 0; idx < dp.size; ++idx) {
        max_length = std::max(std::max(max_length, dp.up[idx]), dp.down[idx]);
    }
    return max_length;
}

// на основе 2х массивов предков восстанавливает ответ, если последним индексом из sequence в нём является idx
std::vector<int> restore_ans_idxes(std::vector<int> &prev_one,
                                   std::vector<int> &prev_two,
                                   int idx) {

    std::vector<int> prev_one_copy(prev_one), prev_two_copy(prev_two);

    std::vector<int> restored_ans;
    while (prev_one_copy[idx] != -1) {
        restored_ans.push_back(idx);
        idx = prev_one_copy[idx];
        swap(prev_one_copy, prev_two_copy);
    }
    restored_ans.push_back(idx);

    reverse(restored_ans.begin(), restored_ans.end());
    return restored_ans;
}


// Подпоследовательностей, максимальной длины может быть несколько.
// Находим индекс, где оканчивается очередная и восстанавливаем все её индексы.
// Далее выбираем ту, что удовлетворяет условию.
std::vector<int> get_ans_indexes(DP &dp, Prev &prev) {

    int max_length = get_max_subsequence_length(dp);

    std::vector<std::vector<int>> maybe_ans_idxes;
    for (int idx = 0; idx < dp.size; ++idx) {

        if (dp.up[idx] == max_length) {
            maybe_ans_idxes.push_back(restore_ans_idxes(prev.down, prev.up, idx));
        }

        if (dp.down[idx] == max_length) {
            maybe_ans_idxes.push_back(restore_ans_idxes(prev.up, prev.down, idx));
        }
    }

    sort(maybe_ans_idxes.begin(), maybe_ans_idxes.end());
    return maybe_ans_idxes[0];
}

std::vector<int> restore_ans(std::vector<int> idxes, std::vector<int> sequence) {
    std::vector<int> ans;
    for (auto idx: idxes) {
        ans.push_back(sequence[idx]);
    }
    return ans;

}


std::vector<int> solve_Tim(std::vector<int> sequence, int totalNumber) {

    DP dp(totalNumber);
    Prev prev(totalNumber);
    fill_dp_and_prev(dp, prev, sequence);


    return restore_ans(get_ans_indexes(dp, prev), sequence);
}
