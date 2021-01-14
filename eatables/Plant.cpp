#include "Plant.h"
#include <iostream>

Plant &Plant::operator=(const Plant &plant) {
    if(this == &plant) return *this;
    Eatables::operator=(plant);
    label = plant.label? make_shared<string>(*plant.label) : nullptr;
    return *this;
}

Plant &Plant::operator=(Plant &&plant) noexcept {
    if(this == &plant) return *this;
    label = plant.label? make_shared<string>(std::move(*plant.label)) : nullptr;
    Eatables::operator=(std::move(plant));
    return *this;
}

void Plant::print(ostream &out) const {
    if(!label) {
        out << "null object" << endl;
        return ;
    }
    Eatables::print(out);
    out << "label: " << *label << endl;
}

Plant::~Plant() = default;

Plant *Plant::clone() const &{
    return new Plant(*this);
}

Plant *Plant::clone() &&{
    return new Plant(std::move(*this));
}
