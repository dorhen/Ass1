#include "../include/Table.h"
#include <iostream>


Table:: Table(int t_capacity) : capacity(t_capacity), open(false) {}

int getCapacity() const {
    return capacity;
}

void addCustomer(Customer *customer) {
    customersList.push_back(*customer);
}

void removeCustomer(int id) {
    for (size_t i = 0; i < customersList.size(); i++) {
        if ((*customersList[i]).getId() == id)
            customersList.erase(i);
    }
}

int getCurrentSize() const {
    return customersList.size();
}

Customer* getCustomer(int id) {
    Customer* ans = nullptr;
    for (size_t i = 0; i < customersList.size(); i++) {
        if ((*customersList[i]).getId() == id)
            ans = customersList[i];
    }
    return ans;
}

std::vector<Customer *>& getCustomers() {
    std::vector < Customer * > &ans = customersList;
    return ans;
}

std::vector<OrderPair>& getOrders() {
    std::vector <OrderPair> &ans = orderList;
    return ans;
}

void order(const std::vector<Dish> &menu) {
    std::vector<int> v;
    std::string s;
    for (size_t i = 0; i < customersList.size(); i++) {
        v = (*customersList[i]).order(menu);
        for (size_t j = 0; j < v.size(); j++) {
            s += customersList[i].getName() + " ordered" + menu[v[j]].getName() + "/n";
            orderList.push_back(OrderPair(customersList[i].getId(), menu[v[j]]));
        }
    }
    std::cout << s << std::endl;
}

void openTable() {
    open = true;
}

void closeTable() {
    open = false;
}

int getBill() {
    int bill = 0;
    for (size_t i = 0; i < orderList.size(); i++) {
        bill += orderList[i].second.getPrice();
    }
    return bill;
}

bool isOpen() {
    return open;
}
