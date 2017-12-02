#include "ClientDB.h"
ClientDB::ClientDB(){}
ClientDB::~ClientDB(){}
void ClientDB::addClient(QString name,QString fname,int id,QString bdate,int cellnb)
{
    bool redundency=false;
    for(int i=0;i<clientVect.size();i++){
        if (clientVect[i].name==name &&
            clientVect[i].fname==fname &&
            clientVect[i].bdate==bdate &&
            clientVect[i].cellnb==cellnb ){
            redundency=true;
            break;
        }}
   if(redundency==false){
   Client c= Client(name,fname,id,bdate,cellnb);
   this->clientVect.push_back(c);
   }
}
vector <vector<QString> > ClientDB::showRenters(){
    using namespace std;
    int i;
    QString id,cellnb,rentedcar;
    vector <vector<QString> > list;
    for(i=0;i<clientVect.size();i++){
        if (clientVect[i].renter==true){
            vector<QString> values;
            values.push_back(clientVect[i].name);
            values.push_back(clientVect[i].fname);
            id=QString::number(clientVect[i].id);
            values.push_back(id);
            values.push_back(clientVect[i].bdate);
            cellnb=QString::number(clientVect[i].cellnb);
            values.push_back(cellnb);
            rentedcar=QString::number(clientVect[i].rentedCar);
            values.push_back(rentedcar);
            list.push_back(values);
        }
    }
    return list;
}
vector <vector<QString> > ClientDB::showAll(){
    using namespace std;
    int i;
    QString id,cellnb,rentedcar;
    vector <vector<QString> > list;
    for(i=0;i<clientVect.size();i++){
            vector<QString> values;
            values.push_back(clientVect[i].name);
            values.push_back(clientVect[i].fname);
            id=QString::number(clientVect[i].id);
            values.push_back(id);
            values.push_back(clientVect[i].bdate);
            cellnb=QString::number(clientVect[i].cellnb);
            values.push_back(cellnb);
            rentedcar=QString::number(clientVect[i].rentedCar);
            values.push_back(rentedcar);
            list.push_back(values);
    }
    return list;
}

