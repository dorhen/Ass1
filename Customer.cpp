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



	CheapCustomer :: CheapCustomer(std::string name, int id) : Customer(name, id), Strategy(-1), ordered(false){}
	std::vector<int> CheapCustomer :: order(const std::vector<Dish> &menu){
		if((!ordered) && (menu.size() > 0)){
			int cheapest = -1;
			for(size_t i=0 ; i < menu.size() ; i++){
				if((menu[i].getPrice() < cheapest) || (cheapest == -1)){
					cheapest = menu[i].getPrice();
					Strategy[0] = i;
				}
			}
			ordered=true;
			return Strategy;
		}
		Strategy.clear();
		return Strategy;
	}			
	std::string CheapCustomer :: toString() const;




	SpicyCustomer :: SpicyCustomer(std::string name, int id) : Customer(name, id), Strategy(-1), ordered(false) {}
    std::vector<int> SpicyCustomer :: order(const std::vector<Dish> &menu){
	    if((ordered) && (menu[Strategy[0]].getType() == BVG))
		    return Strategy;
	    else if(ordered){
		   	 int cheapest=-1;
		   	 for(size_t i=0 ; i < menu.size() ; i++){
				 if(menu[i].getType() == BVG){
					if((menu[i].getPrice() < cheapest) || (cheapest == -1)){
						cheapest = menu[i].getPrice();
						Strategy[0] = i;
					}
				}
			}
		if(cheapest == -1){
			Strategy.clear();
			retrun Strategy;
		}
	    }
	    int exp=0;
	    for(size_t i=0;i<menu.size();i++){
		    if((menu[i].getType==SPC) && (menu[i].getPrice()>exp)){
			    exp = menu[i].getPrice();
			    Strategy[0]=i;
		    }
	    }
	    if(exp == 0)
		    Strategy.clear();
	    ordered == true;
	    return Strategy;
    }	    
    std::string SpicyCustomer :: toString() const;




	AlchoholicCustomer :: AlchoholicCustomer(std::string name, int id) : Customer(name, id), current=0 {}
	AlchoholicCustomer :: Sort(){
		std::vector<Dish> Sorted;
		int i=1;
		Sorted.resize(Drinks.size());
		Sorted[0]=Drinks[0];
		while(i<Drinks.size()){
			int j=i-1;
			while(Drinks[i].getPrice()<Sorted[j].getPrice()){
				Sorted[j+1]=Sorted[j];
				j--;
			}
			Sorted[j+1]=Drinks[i];
			i++;
		}
		Drinks = Sorted; //not sure
	}
    std::vector<int> AlchoholicCustomer :: order(const std::vector<Dish> &menu){
	    if(current>0){
		    if(current<Drinks.size()){
			    Strategy[0]=Drinks[current].getId();
			    current++;
		    }
		    else Strategy.clear();
		    retrurn Strategy;
	    }
	    for(size_t i=0 ; i < menu.size() ; i++){
		    if(menu[i].getType()==ALC)
			    Drinks.push_back(menu[i]);
	    }
	    Sort();
	    Strategy.push_back(Drinks[current].getId());
	    current++;
	    return Strategy;
    }
	    
    std::string AlchoholicCustomer :: toString() const;


#endif
