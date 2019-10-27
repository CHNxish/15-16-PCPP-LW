#ifndef _SALES_ITEM_HPP_
#define _SALES_ITEM_HPP_

#include <string>
#include <iostream>
using namespace std;

class SalesItem{
    private:
        string name;
        int number;
        double unitPrice;

    public:
        SalesItem();
        SalesItem(string name, int number, double unitPrice);   // 构造函数
        ~SalesItem();                                           // 析构函数
        SalesItem Add(SalesItem si1, SalesItem si2);            // +
        friend istream &operator>>(istream &input, SalesItem &si){
            input >> si.name >> si.number >> si.unitPrice;
            return input;
        }
        void GetValue();                           // >>
        void PutValue();                           // <<
        void Assignment(SalesItem si2);        // =
        bool IsSame(SalesItem si);                                // ==
};

SalesItem::SalesItem(){
    this -> name = "";
    this -> number = -1;
    this -> unitPrice = -1;
}

SalesItem::SalesItem(string name, int number, double unitPrice){
    this -> name = name;
    this -> number = number;
    this -> unitPrice = unitPrice;
}

SalesItem::~SalesItem(){}

SalesItem SalesItem::Add(SalesItem si1, SalesItem si2){
	SalesItem siSum(si1.name, si1.number + si2.number, si1.unitPrice);

    return siSum;
}

void SalesItem::GetValue(){
    std::cin >> this -> name >> this -> number >> this -> unitPrice;
}

void SalesItem::PutValue(){
    std::cout << this -> name << " " << this -> number << " " << this -> unitPrice * \
    this -> number << " " << this -> unitPrice << std::endl;
}

void SalesItem::Assignment(SalesItem si){
    this -> name = si.name;
    this -> number = si.number;
    this -> unitPrice = si.unitPrice;
}

bool SalesItem::IsSame(SalesItem si){
    if(this -> name == si.name){
        return true;
    }
    else{
        return false;
    }
}

#endif
