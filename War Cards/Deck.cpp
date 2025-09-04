// Deck.cpp
#include "Deck.h"
#include <algorithm>
#include <random>

Deck::Deck() {
    for (auto s : { Suit::Clubs, Suit::Diamonds, Suit::Hearts, Suit::Spades })
        for (int v = int(Value::Deuce); v <= int(Value::Ace); ++v)
            cards_.emplace_back(static_cast<Value>(v), s);
}

void Deck::shuffle() {
    static std::mt19937 rng{ std::random_device{}() };
    std::shuffle(cards_.begin(), cards_.end(), rng);
}

Card Deck::drawTop() {
    Card c = cards_.back();
    cards_.pop_back();
    return c;
}

bool Deck::empty() const noexcept {
    return cards_.empty();
}
