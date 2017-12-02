#ifndef CAR_H
#define CAR_H
#include <QString>
class Car
{
public:
    QString model;
    int lplate;
    QString color;
    int hp;
    bool rented;
    Car(QString,int,QString,int);
    Car(QString,int,QString,int,bool);
    Car();
};
QDataStream &operator<<(QDataStream &out, const Car &cr);
QDataStream &operator>>(QDataStream &in, Car &cr);
#endif // CAR_H
