#include "../include/Table.h"

    Table(int t_capacity) : capacity(t_capacity), open(false){
    }
    int getCapacity() const{
        return capacity;
    }
    void addCustomer(Customer* customer){
        customersList.push_back(customer);
    }
    void removeCustomer(int id){
        for(size_t i=0 ; i< customerList.size() ; i++){
            if((*customerList[i]).getId() == id)
                customerList.erase(i);
        }
    Customer* getCustomer(int id){
        for(size_t i=0 ; i< customerList.size() ; i++){
            if((*customerList[i]).getId() == id)
                return *customerList[i];
        }
    std::vector<Customer*>& getCustomers(){
        vector<Customer*>& ans= customersList;
        retrun ans;
    }
    std::vector<OrderPair>& getOrders(){
        vector<OrderPair>& ans= orderList;
        retrun ans;
    }
    void order(const std::vector<Dish> &menu){
        std :: vector<int> v;
        std :: string s;
        for(size_t i=0 ; i< customerList.size() ; i++){
            v = (*customersList[i]).order(menu);
            for(size_t j=0 ; j< v.size() ; j++){
                s += customersList[i].getName() + " ordered" + menu[v[j]].getName() + "/n";
                orderList.push_back(OrderPair(customersList[i].getId(),menu[v[j]]));
            }
        }
        std :: cout << s << endl;
    }
    void openTable(){
        open(true);
    }
    void closeTable(){
        open(false);
    }
    int getBill(){
        int bill=0;
        for(size_t i=0 ; i< orderList.size() ; i++){
            bill += orderList[i].second.getPrice();
        }
        return bill;
    }
    bool isOpen(){
        return open;
    }
