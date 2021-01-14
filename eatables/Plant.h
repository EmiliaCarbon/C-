#ifndef PRIMER_PLANT_H
#define PRIMER_PLANT_H

#include "Eatables.h"

class Plant: public Eatables{
private:
    shared_ptr<string> label = nullptr;

public:
    Plant() = default;
    Plant(string name, double price, string lab):
        Eatables(std::move(name), price), label(make_shared<string>(std::move(lab))){}
    Plant(const Plant &plant):      // 拷贝构造函数
        Eatables(plant), label(plant.label? make_shared<string>(*plant.label) : nullptr){}
    Plant(Plant &&plant) noexcept:   //移动构造函数
        Eatables(std::move(plant)), label(plant.label? make_shared<string>(std::move(*plant.label)) : nullptr){}

    Plant &operator=(const Plant&);    //拷贝赋值函数
    Plant &operator=(Plant &&) noexcept;     //移动赋值函数

    void print(ostream&) const override;
    Plant *clone() const & override;
    Plant *clone() && override;
    ~Plant() override;
};


#endif //PRIMER_PLANT_H
