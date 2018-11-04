#include "../include/Restaurant.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


void Restaurant(const string &configFilePath): open(true){
    ifstream inFile;
    inFile.open(configFilePath);
    if(!inFile.is_open()){
        exit(1);
    }
    string line;
    int count = 0;
    while(!inFile.eof()){
      getline(inFile,line);
      if(line.size() == 0 )
	continue;
      else if(line[0] == "#"){
	count++;
	continue;
      }
      int dishID = 0;
      switch(count){
	case 1:
            stringstream num(line);
            int numOfTables = 0;
            num >> numOfTables;
            vector<int> t(numOfTables);
            break;
	  
	case 2:
            while(!line.size() == 0){
                if(line.find(",")){
                    string numWord = line.substr(0,line.find(","));
                    line = line.substr(line.find(",")+1);
                    stringstream num(numWord);
                    int tSize = 0;
                    num >> tSize;
                    tables.push_back(new Table(tSize));
                    break;
                }
                else{
                    stringstream num(line);
                    int tSize = 0;
                    num >> tSize;
                    tables.push_back(new Table(tSIze));
                    continue;
                }
            }
            break;
        case 3:
            string name = line.substr(0,line.find(","));
            line = line.substr(line.find(",")+1);
            string dishType = line.substr(0,line.find(","));
            string numWord = line.substr(line.find(",")+1);
            stringstream num(numWord);
            int price = 0;
            num >> price;
            menu.push_back(new Dish(dishID,name,price,convert(dishType)));
            dishID++;
      }
    }
    inFile.close();
}

void start(){

}

int getNumOfTables() const{
    return tables.size();
}

vector<Dish>& getMenu(){
    vector<Dish> &dishRef = menu;
    return dishRef;
}

Table* getTable(int ind){
    return tables[ind];
}

DishType convert(string str){
    if(str == "VEG") return VEG;
    else if(str == "SPC") return SPC;
    else if(str == "BVG") return BVG;
    else if(str == "ALC") return ALC;
    return 0;
}

/*
void copy(const Restaurant& other){
    open = other.open;
    for(i = 0; i< other.tables.size(); i++)
        tables[i] = new Table(other.tables[i]);
    menu(other.menu);
    for(i =0; i<other.actionsLog.size(); i++)
        actionsLog[i] = new BaseAction(other.actionsLog[i]);
}

void steal(Restaurant& other){
    open = other.open;
    tables = other.tables;
    other.tables = nullptr;
    menu = other.menu;
    other.menu = nullptr;
    actionsLog = other.actionsLog;
    other.actionsLog = nullptr;
}
    
    
void clean(){
    for(i = 0; i < tables.size(); i++){
        delete tables[i];
    }
    delete tables;
    delete menu;
    for(i = 0; i < actionsLog.size(); i++){
        delete actionsLog[i];
    }
    actionsLog delete;
    open = false;
}

virtual ~Restaurant(){
    for(i = 0; i < tables.size(); i++){
        delete tables[i];
    }
    delete tables;
    for(i = 0; i < actionsLog.size(); i++){
        delete actionsLog[i];
    }
    actionsLog delete;
}

Restaurant(const Restaurant& rhs){
    copy(rhs)
}

Restaurant& operator=(const Restaurant& rhs){
    if(&rhs != this)
    {
        this.clean();
        copy(rhs)
    }
    return *this;
        
}

Restaurant(const Restaurant&& rhs){
    steal(rhs)
}

Restaurant& operator=(const Restaurant&& rhs){
    clean();
    steal(rhs);
    return *this;
}*/
