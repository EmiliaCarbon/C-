#include "Eatables.h"
#include <iostream>

Eatables::Eatables(Eatables &&eat) noexcept : name(std::move(eat.name)), price(eat.price) {}

Eatables &Eatables::operator=(const Eatables &eat) {
    if(this == &eat) return *this;
    name = eat.name;
    price = eat.price;
    return *this;
}

Eatables &Eatables::operator=(Eatables &&eat)  noexcept {
    if(this == &eat) return *this;
    name = std::move(eat.name);
    price = eat.price;
    return *this;
}

void Eatables::print(ostream &out) const {
    out << "food name: " << name << "\n"
    << "price: " << price << endl;
}

Eatables::~Eatables() = default;

Eatables *Eatables::clone() const &{
    return new Eatables(*this);
}

Eatables *Eatables::clone() &&{
    return new Eatables(std::move(*this));
}
