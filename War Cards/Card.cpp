// Card.cpp
#include "Card.h"

std::string Card::suitName(Suit s) {
    switch (s) {
    case Suit::Clubs:    return "Clubs";
    case Suit::Diamonds: return "Diamonds";
    case Suit::Hearts:   return "Hearts";
    case Suit::Spades:   return "Spades";
    }
    throw std::out_of_range("Invalid Suit");
}

std::string Card::valueName(Value v) {
    switch (v) {
    case Value::Deuce: return "2";
    case Value::Three: return "3";
    case Value::Four:  return "4";
    case Value::Five:  return "5";
    case Value::Six:   return "6";
    case Value::Seven: return "7";
    case Value::Eight: return "8";
    case Value::Nine:  return "9";
    case Value::Ten:   return "10";
    case Value::Jack:  return "Jack";
    case Value::Queen: return "Queen";
    case Value::King:  return "King";
    case Value::Ace:   return "Ace";
    }
    throw std::out_of_range("Invalid Value");
}
