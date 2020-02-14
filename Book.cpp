#include "Book.h"
#include <iostream>

using namespace std;

Book::Book(string _title, string _author, string _status, int _year, double _price){
    title = _title;
    author = _author;
    status = _status;
    year = _year;
    price = _price;
}

Book::Book(){
}

void Book::toString(){
    cout<<"  Titulo: "<<title<<endl;
    cout<<"  Autor: "<<author<<endl;
    cout<<"  Estado: "<<status<<endl;
    cout<<"  Año: "<<year<<endl;
    cout<<"  Precio: "<<price<<endl;
}

void Book::update(string _title, string _author, string _status, int _year, double _price){
    title = _title;
    author = _author;
    status = _status;
    year = _year;
    price = _price;
}

string Book::getStatus(){
    return status;
}

double Book::getPrice(){
    return price;
}

void Book::buy(){
    status = "Vendido";
}

string Book::getAuthor(){
    return author;
}

string Book::getTitle(){
    return title;
}

Book::~Book(){
}