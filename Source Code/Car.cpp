#include "Car.h"
#include <QDataStream>
QString model;
int lplate;
QString color;
int hp;
bool rented;
Car::Car(QString model,int lplate,QString color,int hp)
{
    this->color=color;
    this->hp=hp;
    this->lplate=lplate;
    this->model=model;
    this->rented=false;
}
Car::Car(QString model,int lplate,QString color,int hp,bool rented)
{
    this->color=color;
    this->hp=hp;
    this->lplate=lplate;
    this->model=model;
    this->rented=rented;
}
Car::Car(){}
QDataStream &operator<<(QDataStream &out, const Car &cr)
{
    out << cr.model << cr.lplate << cr.color << cr.hp << cr.rented ;
    return out;
}
QDataStream &operator>>(QDataStream &in, Car &cr)
{
    QString model;
    int lplate;
    QString color;
    int hp;
    bool rented;
    in >> model >> lplate >> color >> hp >> rented;
    cr = Car(model,lplate,color,hp,rented);
    return in;
}

