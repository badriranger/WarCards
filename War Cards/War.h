// War.h
#ifndef WAR_H
#define WAR_H

#include "Hand.h"
#include "Card.h"
#include <vector>

// A stripped-down engine that can be stepped or run to completion.
class War {
public:
    War(Hand& p1, Hand& p2);

    // Advance exactly one round. Returns false if game is over.
    bool playRound();

    // After playRound(), these give you the two face-up cards:
    Card lastCard1() const;
    Card lastCard2() const;

    int getRounds() const;  // total rounds played
    int getWars()   const;  // total wars triggered

private:
    Hand& player1_;
    Hand& player2_;
    Card        last1_{}, last2_{};
    int         rounds_ = 0;
    int         wars_ = 0;

    // Handles the “war” tie-resolution, collecting into spoils.
    int resolveWar(std::vector<Card>& spoils);
};

#endif // WAR_H
