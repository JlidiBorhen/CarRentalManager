#ifndef CLIENTDB_H
#define CLIENTDB_H
#include "Client.h"
#include <vector>
#include <QString>
using namespace std;
class ClientDB
{
public:
    vector<Client>  clientVect;
    void addClient(QString,QString,int,QString,int);
    vector <vector<QString> >showRenters();
    vector <vector<QString> >showAll();
    ClientDB();
    ~ClientDB();
};
#endif // CLIENTDB_H
