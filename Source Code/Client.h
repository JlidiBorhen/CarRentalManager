#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
class Client
{
public:
    QString name;
    QString fname;
    int id;
    QString bdate;
    int cellnb;
    bool renter;
    int rentedCar;
    Client(QString,QString,int,QString,int);
    Client(QString,QString,int,QString,int,bool,int);
    Client();
    ~Client();
    friend class CarDB;
};
QDataStream &operator<<(QDataStream &out, const Client &cl);
QDataStream &operator>>(QDataStream &in, Client &cl);
#endif // CLIENT_H
