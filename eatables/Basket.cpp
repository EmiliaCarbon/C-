#include "Basket.h"
#include "Eatables.h"

bool Basket::compare(const shared_ptr<Eatables> &eat1, const shared_ptr<Eatables> &eat2) {
    return eat1->name < eat2->name;
}

Basket & Basket::push(const Eatables &eat) {
    container.insert(shared_ptr<Eatables>(eat.clone()));
    return *this;
}

Basket & Basket::push(Eatables &&eat) {
    container.insert(shared_ptr<Eatables>(std::move(eat).clone()));
    return *this;
}

ostream &operator<<(ostream &out, const Basket &basket) {
    for(const auto& p : basket.container) {
        p->print(out);
        out << endl;
    }
    return out;
}
