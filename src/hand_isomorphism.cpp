#include "hand_isomorphism.h"

#include <iostream>

extern "C" {
struct hand_isomorphism_state* hand_isomorphism_state_create();
void hand_isomorphism_state_destroy(void* state);
struct hand_indexer_t* hand_indexer_init(void*indexer_global_state, uint_fast32_t rounds, const uint8_t cards_per_round[]);
void hand_indexer_free(void* indexer);
uint64_t hand_indexer_size(void* indexer, uint_fast32_t round);
uint64_t hand_index_last(void* global_state, void* indexer, const uint8_t* cards);
bool hand_unindex(void* global_state, void* indexer, uint_fast32_t round, uint64_t index, uint8_t *cards);
}

HandIsomorpshim::HandIndexer::HandIndexer(std::vector<std::vector<uint8_t>> const &cards_per_round):cards_per_round(cards_per_round){
    indexer_global_state = hand_isomorphism_state_create();
    for (auto const& cards:cards_per_round){
        indexers.push_back(hand_indexer_init(indexer_global_state, cards.size(), cards.data()));
    }
}

HandIsomorpshim::HandIndexer::~HandIndexer(){
    hand_isomorphism_state_destroy(indexer_global_state);
    for(auto& indexer:indexers){
        hand_indexer_free(indexer);
    }
}

uint64_t HandIsomorpshim::HandIndexer::roundSize(int round) const{
    return hand_indexer_size(indexers[round], cards_per_round[round].size() - 1);
}

uint64_t HandIsomorpshim::HandIndexer::index(int round, uint8_t const *cards) const{
    return hand_index_last(indexer_global_state, indexers[round], cards);
}

bool HandIsomorpshim::HandIndexer::unindex(int round, uint64_t index, uint8_t *output) const{
    return hand_unindex(indexer_global_state, indexers[round], cards_per_round[round].size() - 1, index, output);
}
