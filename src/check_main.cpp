#include "hand_isomorphism.h"
#include <iostream>

int main(){
    std::vector<std::vector<uint8_t>> cardsPerRound = {{2},{2,3},{2,3,1},{2,3,1,1}};
    HandIsomorpshim::HandIndexer indexer(cardsPerRound);
    for (size_t i = 0; i < 4; i++){
        std::cout << indexer.roundSize(i) << std::endl;
    }
    
    return 0;
}