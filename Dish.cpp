
#include "../include/Dish.h"

    Dish(int d_id, std::string d_name, int d_price, DishType d_type) : id(d_id), price(d_price), type(d_type), name(d_name) {}

    int getId() const{
        return id;
    }
    std::string getName() const{
        return name;
    }
    int getPrice() const{
        return price;
    }
    DishType getType() const{
        return type;
    }

