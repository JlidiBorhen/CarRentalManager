#include "CarDB.h"
#include "ClientDB.h"
CarDB::CarDB(){}
void CarDB::addCar(QString model,int lplate,QString color,int hp)
{
    Car c= Car(model,lplate,color,hp);
    carVect.push_back(c);
}
void CarDB::rmCar(int lplate)
{   int i;
    for (i=0;i<this->carVect.size();i++){
        if (carVect[i].lplate==lplate) break;
    }
    carVect.erase(carVect.begin()+i);
}
void CarDB::rentCar(int lpp,int idd,ClientDB &cldb){
    int i=0;
   for ( i=0;i<cldb.clientVect.size();i++){
        if (cldb.clientVect[i].id==idd)break;
    }
    cldb.clientVect[i].renter=true;
   cldb.clientVect[i].rentedCar=lpp;

    for (i=0;i<carVect.size();i++){
        if (carVect[i].lplate==lpp) break;
    }
   carVect[i].rented=true;
}
void CarDB::returnCar(int lpp,ClientDB& cldb){
    int i;
    for (i=0;i<carVect.size();i++){
        if (carVect[i].lplate==lpp) break;
    }
    carVect[i].rented=false;
    for (i=0;i<cldb.clientVect.size();i++){
        if (cldb.clientVect[i].rentedCar==lpp) break;
    }
    cldb.clientVect[i].rentedCar=0;
    cldb.clientVect[i].renter=false;
}
vector <vector<QString> > CarDB::showAll(){
    using namespace std;
    int i;
    QString lplate,hp;
    vector <vector<QString> > list;
    for(i=0;i<carVect.size();i++){
            vector<QString> values;
            values.push_back(carVect[i].model);
            lplate=QString::number(carVect[i].lplate);
            values.push_back(lplate);
            values.push_back(carVect[i].color);
            hp=QString::number(carVect[i].hp);
            values.push_back(hp);
            list.push_back(values);
    }
    return list;
}
vector <vector<QString> > CarDB::showAvailable(){
    using namespace std;
    int i;
    QString lplate,hp;
    vector <vector<QString> > list;
    for(i=0;i<carVect.size();i++){
        if(carVect[i].rented==false){
            vector<QString> values;
            values.push_back(carVect[i].model);
            lplate=QString::number(carVect[i].lplate);
            values.push_back(lplate);
            values.push_back(carVect[i].color);
            hp=QString::number(carVect[i].hp);
            values.push_back(hp);
            list.push_back(values);
        }
    }
    return list;
}
vector <vector<QString> > CarDB::showSearch(QString model){
    using namespace std;
    int i;
    QString lplate,hp;
    vector <vector<QString> > list;
    for(i=0;i<carVect.size();i++){
        if(carVect[i].model==model && carVect[i].rented==false ){
            vector<QString> values;
            values.push_back(carVect[i].model);
            lplate=QString::number(carVect[i].lplate);
            values.push_back(lplate);
            values.push_back(carVect[i].color);
            hp=QString::number(carVect[i].hp);
            values.push_back(hp);
            list.push_back(values);
        }
    }
    return list;
}
