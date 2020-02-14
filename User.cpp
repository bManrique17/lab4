#include "User.h"

User::User(string _user, string _password, string _name, int _age, double _money){
    user = _user;
    password = _password;
    name = _name;
    age = _age;
    money = _money;
}

User::User(){
}

string User::getName(){
    return name;
}

string User::getUser(){
    return user;
}

string User::getPassword(){
    return password;
}

double User::getMoney(){
    return money;
}

void User::buy(double price){
    money -=  price;
}

void User::setPassword(string _password){
    password = _password;
}

void User::addMoney(double _money){
    money += _money;
}

User::~User(){
}