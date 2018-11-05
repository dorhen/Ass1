#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <vector>
#include <string>
#include "Dish.h"


    Customer(std::string c_name, int c_id): name(d_name), id(d_id){}
    
    virtual std::vector<int> order(const std::vector<Dish> &menu)=0;
    virtual std::string toString() const = 0;
    
    std::string getName() const{
        return name;
    }
    int getId() const{
        return id;
    }



	VegetarianCustomer :: VegetarianCustomer(std::string name, int id): Customer(name, id) : Customer(name, id) , Strategy(-1,-1){
	}
	std::vector<int> VegetarianCustomer :: order(const std::vector<Dish> &menu){
    		if((Strategy.size() == 2) && (Strategy[0] == -1)){
			int expBVG = -1;
			for(size_t i=0 ; i < menu.size() ; i++){
				if ((Strategy[0]==-1) && (menu[i].getType() == VEG))
					Strategy[0] = i;
				if ((menu[i].getType == BVG) && (menu[i].getPrice() > expBVG)){
					Strategy[1] = i;
					expBVG = menu[i].getPrice();
				}
			}
			if((Strategy[1] == -1)  || (Strategy[0] == -1))
				Strategy.clear();
		}
		return Strategy;
	}
	
	std::string VegetarianCustomer :: toString() const;



	CheapCustomer :: CheapCustomer(std::string name, int id) : Customer(name, id), Strategy(-1){}
	std::vector<int> CheapCustomer :: order(const std::vector<Dish> &menu){
		if(Strategy[0] == -1){
		
			int cheapest = -1;
			for(size_t i=0 ; i < menu.size() ; i++){
				if((menu[i].getPrice() < cheapest) || (cheapest == -1)){
					cheapest = menu[i].getPrice();
					Strategy[0] = i;
				}
			}
			
				
	std::string CheapCustomer :: toString() const;



class SpicyCustomer : public Customer {
public:
	SpicyCustomer(std::string name, int id) : Customer(name, id) {}
    std::vector<int> order(const std::vector<Dish> &menu);
    std::string toString() const;
private:
};


class AlchoholicCustomer : public Customer {
public:
	AlchoholicCustomer(std::string name, int id) : Customer(name, id) {}
    std::vector<int> order(const std::vector<Dish> &menu);
    std::string toString() const;
private:
};


#endif
