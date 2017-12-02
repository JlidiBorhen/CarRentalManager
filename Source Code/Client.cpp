#include "Client.h"
#include <QDataStream>
Client::Client(QString name,QString fname,int id,QString bdate,int cellnb)
{
    this->name=name;
    this->fname=fname;
    this->id=id;
    this->bdate=bdate;
    this->cellnb=cellnb;
    this->renter=false;
    this->rentedCar=0;
}
Client::Client(QString name,QString fname,int id,QString bdate,int cellnb, bool renter,int rentedCar)
{
    this->name=name;
    this->fname=fname;
    this->id=id;
    this->bdate=bdate;
    this->cellnb=cellnb;
    this->renter=renter;
    this->rentedCar=rentedCar;
}
Client::Client()
{
    this->name="";
    this->fname="";
    this->id=0;
    this->bdate="";
    this->cellnb=0;
    this->renter=false;
    this->rentedCar=0;
}
Client::~Client(){}
QDataStream &operator<<(QDataStream &out, const Client &cl)
{
    out << cl.name << cl.fname << cl.id << cl.bdate << cl.cellnb << cl.renter << cl.rentedCar;
    return out;
}
QDataStream &operator>>(QDataStream &in, Client &cl)
{
    QString name;
    QString fname;
    int id;
    QString bdate;
    int cellnb;
    bool renter;
    int rentedCar;
    in >> name >> fname >> id >> bdate >> cellnb >> renter >> rentedCar;
    cl = Client(name,fname,id,bdate,cellnb,renter,rentedCar);
    return in;
}
