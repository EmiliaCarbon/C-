#ifndef PRIMER_BASKET_H
#define PRIMER_BASKET_H

#include <set>
#include <iostream>
#include <memory>

using namespace std;

class Eatables;
//用于存放Eatables及其子类的容器
class Basket {
    friend ostream &operator<<(ostream &out, const Basket &basket);
private:
    static bool compare(const shared_ptr<Eatables>&, const shared_ptr<Eatables>&);

private:
    // multiset<Eatables, bool(*)(const Eatables&, const Eatables&)> container{compare};
    multiset<shared_ptr<Eatables>, decltype(compare)*> container{compare};

public:
    Basket() = default;

    Basket &push(const Eatables&);
    Basket &push(Eatables&&);
};

ostream &operator<<(ostream &out, const Basket &basket);

#endif //PRIMER_BASKET_H
