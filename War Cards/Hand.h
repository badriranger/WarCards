// Hand.h
#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"

class Hand {
public:
    void placeBottom(const Card& c);  // win or collect cards
    Card drawTop();                   // play from top
    Card drawBottom();                // for war face-down
    bool empty() const noexcept;
    int size() const noexcept;

private:
    std::vector<Card> cards_;
};

#endif // HAND_H
