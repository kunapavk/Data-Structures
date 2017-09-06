//Implementation file for the ClassTask3

#include "ClassTask3.h"
#include <iomanip>
#include <cstdlib>

//Implementation function for setters

void Prod::setid(int x){id = x;}
void Prod::setunits(int y){units = y;}
void Prod::setprices(double z){prices = z;}
void Prod::setsales(double i){sales = i;}

//Implementation function for getters

int Prod::getid() const{return id;}
int Prod::getunits() const{return units;}
double Prod::getprices() const{return prices;}
double Prod::getsales() const{return sales;}