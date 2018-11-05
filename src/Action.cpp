#include "../include/Action.h"
#include "../include/Table.h"
#include <iostream>W

//BaseAction

//Constructor
BaseAction::BaseAction() : errorMsg(""), status(PENDING){}
//Methods
ActionStatus BaseAction::getStatus() const{
    return this.status;
}
void BaseAction::updateArgs(std::string args) {
    this->argsDelivered = args;
}
void BaseAction::complete() {
    this->status = COMPLETED;
}
void BaseAction::error(std::string errorMsg){
    this->errorMsg = errorMsg;
    this->status = ERROR;
}
std::string BaseAction::getArgs() const{
    return this->argsDelivered;
}
std::string BaseAction::getErrorMsg() const {
    return this->errorMsg;
}


//OpenTable

//Constructor
OpenTable::OpenTable(int id, std::vector<Customer *> &customersList) : BaseAction(), tableId(id), customers(customersList){}
//Methods
void OpenTable::act(Restaurant &restaurant) {
    Table *t = restaurant.getTable(this->tableId);
    if (!t || !(t->isOpen()))
        this->error("Table does not exist or is already open");
    else{
        t->openTable();
        for(size_t i = 0; i < t->getCustomers().size() ; i++)
            t->addCustomer(t->getCustomers()[i]);
    }
}
std::string OpenTable::toString() const {
    if(this->getStatus() == 2)
        std::cout << this->getArgs() << " Error: " << this->getErrorMsg() << endl;
    else
        std::cout << this->getArgs() << "Completed" << endl;
}


//Order

//Constructor
Order::Order(int id) : BaseAction(), tableId(id){}
//Methods
void Order::act(Restaurant &restaurant) {
    Table *t = restaurant.getTable(this->tableId);
        if (!t || !(t->isOpen()))
            this->error("Table does not exist or is already open");
        else
            t->order(restaurant.getMenu());
}


//MoveCustomer

//Constructor
MoveCustomer::MoveCustomer(int src, int dst, int customerId) : srcTable(src), dstTable(dst), id(customerId){}
//Methods
void MoveCustomer::act(Restaurant &restaurant) {
    Table *t = restaurant.getTable(this->tableId);
    if(!t || !(t->isOpen()) || t->getCapacity() == t->getCurrentSize() || !t->getCustomer(this->id))
        this->error("Cannot move customer");
    else{

    }
}