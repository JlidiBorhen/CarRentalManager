#ifndef CARDB_H
#define CARDB_H
#include "Car.h"
#include "ClientDB.h"
#include <vector>
using namespace std;
class CarDB
{
public:
   vector <Car> carVect;
   vector <vector<QString> > showAll();
   vector <vector<QString> > showAvailable();
   vector <vector<QString> > showSearch(QString);
   void addCar(QString,int,QString,int);
   void rentCar(int,int,ClientDB&);
   void returnCar(int,ClientDB&);
   void rmCar(int);
   CarDB();
};
#endif // CARDB_H
