#pragma once

#include <cinttypes>
#include <vector>

namespace HandIsomorpshim {

class HandIndexer {
public:
    HandIndexer(std::vector<std::vector<uint8_t>> const& cards_per_round);
    ~HandIndexer();
    uint64_t roundSize(int round) const;
    uint64_t index(int round, uint8_t const* cards) const;
    bool unindex(int round, uint64_t index, uint8_t *output) const;
private:
    std::vector<std::vector<uint8_t>> const& cards_per_round;
    void* indexer_global_state;
    std::vector<void*> indexers;
};

}