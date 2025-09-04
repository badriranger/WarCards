// War.cpp
#include "War.h"

War::War(Hand& p1, Hand& p2)
    : player1_(p1), player2_(p2) {}

bool War::playRound() {
    if (player1_.empty() || player2_.empty())
        return false;

    ++rounds_;
    Card c1 = player1_.drawTop();
    Card c2 = player2_.drawTop();
    last1_ = c1;
    last2_ = c2;

    std::vector<Card> spoils{ c1, c2 };

    if (c1.getValue() == c2.getValue()) {
        ++wars_;
        int winner = resolveWar(spoils);
        for (auto& card : spoils)
            (winner == 1 ? player1_ : player2_).placeBottom(card);
    }
    else {
        int winner = (c1.getValue() > c2.getValue() ? 1 : 2);
        for (auto& card : spoils)
            (winner == 1 ? player1_ : player2_).placeBottom(card);
    }

    return !player1_.empty() && !player2_.empty();
}

Card War::lastCard1() const { return last1_; }
Card War::lastCard2() const { return last2_; }
int  War::getRounds() const { return rounds_; }
int  War::getWars()   const { return wars_; }

int War::resolveWar(std::vector<Card>& spoils) {
    // Each tie: 3 face-down + 1 face-up, repeat if tied again
    while (true) {
        if (player1_.size() < 4) return 2;
        if (player2_.size() < 4) return 1;
        for (int i = 0; i < 3; ++i) {
            spoils.push_back(player1_.drawTop());
            spoils.push_back(player2_.drawTop());
        }
        Card c1 = player1_.drawTop();
        Card c2 = player2_.drawTop();
        last1_ = c1;
        last2_ = c2;
        spoils.push_back(c1);
        spoils.push_back(c2);

        if (c1.getValue() != c2.getValue())
            return (c1.getValue() > c2.getValue()) ? 1 : 2;

        ++wars_;
    }
}
