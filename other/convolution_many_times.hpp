#pragma once

#include <vector>
#include <queue>
#include <utility>
#include <cassert>

template <typename Seq, typename Conv>
Seq convolution_many_times(std::vector<Seq> seqs, Conv conv) {
    assert(!seqs.empty());
    std::queue<Seq> que;
    for (int i = 0; i < (int) seqs.size(); ++i) {
        que.emplace(std::move(seqs[i]));
    }
    while (que.size() >= 2) {
        Seq s0 = que.front();
        que.pop();
        Seq s1 = que.front();
        que.pop();
        que.emplace(conv(std::move(s0), std::move(s1)));
    }
    return que.front();
}