#ifndef PRIMER_EATABLES_H
#define PRIMER_EATABLES_H

#include <string>
#include <memory>
#include <utility>

using namespace std;

class Eatables {
    friend class Basket;

protected:
    string name;
    double price = 0.0;

public:
    Eatables() = default;
    Eatables(string name, double price):
        name(std::move(name)), price(price){}
    Eatables(const Eatables&) = default;          //拷贝构造函数
    Eatables(Eatables&&) noexcept;               //移动构造函数

    Eatables &operator=(const Eatables&);       //拷贝赋值函数
    Eatables &operator=(Eatables&&) noexcept;            //移动赋值函数

    virtual void print(ostream&) const;
    virtual Eatables *clone() const &;
    virtual Eatables *clone() &&;
    virtual ~Eatables();
};


#endif //PRIMER_EATABLES_H
