// Card.h
#ifndef CARD_H
#define CARD_H

#include <string>
#include <stdexcept>

enum class Suit { Clubs, Diamonds, Hearts, Spades };
enum class Value {
    Deuce = 2, Three, Four, Five, Six,
    Seven, Eight, Nine, Ten,
    Jack, Queen, King, Ace
};

class Card {
public:
    Card(Value value = Value::Deuce, Suit suit = Suit::Clubs)
        : value_(value), suit_(suit) {}

    Suit  getSuit()  const noexcept { return suit_; }
    Value getValue() const noexcept { return value_; }
    std::string name() const {
        return valueName(value_) + " of " + suitName(suit_);
    }

    static std::string suitName(Suit s);
    static std::string valueName(Value v);

private:
    Value value_;
    Suit  suit_;
};

#endif // CARD_H
