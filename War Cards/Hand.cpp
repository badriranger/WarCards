// Hand.cpp
#include "Hand.h"

void Hand::placeBottom(const Card& c) {
    cards_.push_back(c);
}

Card Hand::drawTop() {
    Card c = cards_.front();
    cards_.erase(cards_.begin());
    return c;
}

Card Hand::drawBottom() {
    Card c = cards_.back();
    cards_.pop_back();
    return c;
}

bool Hand::empty() const noexcept {
    return cards_.empty();
}

int Hand::size() const noexcept {
    return int(cards_.size());
}
