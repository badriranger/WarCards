// Deck.h
#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

class Deck {
public:
    Deck();               // build the full 52-card deck
    void shuffle();       // randomize it
    Card drawTop();       // deal one card
    bool empty() const noexcept;

private:
    std::vector<Card> cards_;
};

#endif // DECK_H
