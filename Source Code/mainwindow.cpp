#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QtWidgets/QMessageBox>
#include <fstream>
#include <iostream>
#include <QDataStream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFile clientsBackupFile("clients.backup");
    QFile carsBackupFile("cars.backup");
    clientsBackupFile.open(QIODevice::ReadOnly);
    carsBackupFile.open(QIODevice::ReadOnly);
    QDataStream clientsBackup(&clientsBackupFile);
    QDataStream carsBackup(&carsBackupFile);
    while (true) {
            if (clientsBackup.atEnd() == true) { break; }
            Client cl;
            clientsBackup >> cl;
            cldb.clientVect.push_back(cl);
        }
    while (true) {
            if (carsBackup.atEnd() == true) { break; }
            Car cr;
            carsBackup >> cr;
            crdb.carVect.push_back(cr);
        }

    clientsBackupFile.close();
    carsBackupFile.close();
    updateCars();
    updateClients();
}

MainWindow::~MainWindow()
{
    QFile clientsBackupFile("clients.backup");
    QFile carsBackupFile("cars.backup");
    clientsBackupFile.open(QIODevice::WriteOnly);
    carsBackupFile.open(QIODevice::WriteOnly);
    QDataStream clientsBackup(&clientsBackupFile);
    QDataStream carsBackup(&carsBackupFile);
    for (size_t i = 0; i < cldb.clientVect.size(); i++) {

           clientsBackup << cldb.clientVect[i];
        }

    for (size_t i = 0; i < crdb.carVect.size(); i++) {
          carsBackup << crdb.carVect[i];
        }

    clientsBackupFile.close();
    carsBackupFile.close();

    delete ui;
}



void MainWindow::on_Rent_Car_Button_clicked()
{
    QString Client_Name = ui->Rent_Name->text();
    QString Client_FirstName = ui->Rent_FirstName->text();
    int Client_ID = (ui->Rent_ID->text()).toInt();
    QString Client_Birthday = ui->Rent_Birthday->text();
    int Client_Telephone = (ui->Rent_Telephone->text()).toInt();
    cldb.addClient(Client_Name,Client_FirstName,Client_ID,Client_Birthday,Client_Telephone);
    int Car_Rent_License = (ui->Rent_Car_License->text()).toInt();
    crdb.rentCar(Car_Rent_License,Client_ID,cldb);
    updateCars();
    updateClients();
}

void MainWindow::on_Return_Car_Button_clicked()
{
    int Car_Return_License = (ui->Return_Car_License->text()).toInt();
   crdb.returnCar(Car_Return_License,cldb);
    updateCars();
    updateClients();
}

void MainWindow::on_Car_Add_clicked()
{
    QString Car_Model = ui->Car_Add_Model->text();
    int Car_License = (ui->Car_Add_License_->text()).toInt();
    QString Car_Color = ui->Car_Color_Add->text();
    int Car_HP = (ui->Car_HP_Add->text()).toInt();
    crdb.addCar(Car_Model,Car_License,Car_Color,Car_HP);
    updateCars();
}

void MainWindow::on_Car_Remove_clicked()
{
    int Car_License_Remove = (ui->Car_License_Remove->text()).toInt();
   crdb.rmCar(Car_License_Remove);
   updateCars();
}

void MainWindow::on_Search_button_clicked()
{
    QString Searched_Car_Name=ui->Search_field->text();

    vector <vector<QString> > listSC =crdb.showSearch(Searched_Car_Name);
    int rowsSC=listSC.size();
    QStandardItemModel *modelSC = new QStandardItemModel(rowsSC,4,this);
    modelSC->setHorizontalHeaderItem(0, new QStandardItem(QString("Model")));
    modelSC->setHorizontalHeaderItem(1, new QStandardItem(QString("License")));
    modelSC->setHorizontalHeaderItem(2, new QStandardItem(QString("Color")));
    modelSC->setHorizontalHeaderItem(3, new QStandardItem(QString("HorsePower")));
    for(int i=0;i<listSC.size();i++){
        for(int j=0;j<4;j++){
    QStandardItem *dataSC = new QStandardItem(*&listSC[i][j]);
    modelSC->setItem(i,j,dataSC);
        }
    }
    ui->Car_Search_Results->setModel(modelSC);
}

void MainWindow::updateCars()
{
    vector <vector<QString> > listCA =crdb.showAll();
    int rowsCA=listCA.size();
    QStandardItemModel *modelCA = new QStandardItemModel(rowsCA,4,this);
    modelCA->setHorizontalHeaderItem(0, new QStandardItem(QString("Model")));
    modelCA->setHorizontalHeaderItem(1, new QStandardItem(QString("License")));
    modelCA->setHorizontalHeaderItem(2, new QStandardItem(QString("Color")));
    modelCA->setHorizontalHeaderItem(3, new QStandardItem(QString("HorsePower")));
    for(int i=0;i<listCA.size();i++){
        for(int j=0;j<4;j++){
    QStandardItem *dataCA = new QStandardItem(*&listCA[i][j]);
    modelCA->setItem(i,j,dataCA);
        }
    }
    ui->all_cars->setModel(modelCA);

    vector <vector<QString> > listCAV =crdb.showAvailable();
    int rowsCAV=listCAV.size();
    QStandardItemModel *modelCAV = new QStandardItemModel(rowsCAV,4,this);
    modelCAV->setHorizontalHeaderItem(0, new QStandardItem(QString("Model")));
    modelCAV->setHorizontalHeaderItem(1, new QStandardItem(QString("License")));
    modelCAV->setHorizontalHeaderItem(2, new QStandardItem(QString("Color")));
    modelCAV->setHorizontalHeaderItem(3, new QStandardItem(QString("HorsePower")));
    for(int i=0;i<listCAV.size();i++){
        for(int j=0;j<4;j++){
    QStandardItem *dataCAV = new QStandardItem(*&listCAV[i][j]);
    modelCAV->setItem(i,j,dataCAV);
        }
    }
    ui->available_cars->setModel(modelCAV);
}

void MainWindow::updateClients()
{
    vector <vector<QString> > listR =cldb.showRenters();
    int rowsR=listR.size();
    QStandardItemModel *modelR = new QStandardItemModel(rowsR,6,this);
    modelR->setHorizontalHeaderItem(0, new QStandardItem(QString("Name")));
    modelR->setHorizontalHeaderItem(1, new QStandardItem(QString("FirstName")));
    modelR->setHorizontalHeaderItem(2, new QStandardItem(QString("ID")));
    modelR->setHorizontalHeaderItem(3, new QStandardItem(QString("Birthday")));
    modelR->setHorizontalHeaderItem(4, new QStandardItem(QString("Telephone")));
    modelR->setHorizontalHeaderItem(5, new QStandardItem(QString("RentedCar")));
    for(int i=0;i<listR.size();i++){
        for(int j=0;j<6;j++){
    QStandardItem *dataR = new QStandardItem(*&listR[i][j]);
    modelR->setItem(i,j,dataR);
        }
    }
    ui->renters_clients->setModel(modelR);

    vector <vector<QString> > listA =cldb.showAll();
    int rowsA=listA.size();
    QStandardItemModel *modelA = new QStandardItemModel(rowsA,6,this);
    modelA->setHorizontalHeaderItem(0, new QStandardItem(QString("Name")));
    modelA->setHorizontalHeaderItem(1, new QStandardItem(QString("FirstName")));
    modelA->setHorizontalHeaderItem(2, new QStandardItem(QString("ID")));
    modelA->setHorizontalHeaderItem(3, new QStandardItem(QString("Birthday")));
    modelA->setHorizontalHeaderItem(4, new QStandardItem(QString("Telephone")));
    modelA->setHorizontalHeaderItem(5, new QStandardItem(QString("RentedCar")));
    for(int i=0;i<listA.size();i++){
        for(int j=0;j<6;j++){
    QStandardItem *dataA = new QStandardItem(*&listA[i][j]);
    modelA->setItem(i,j,dataA);
        }
    }
    ui->all_clients->setModel(modelA);

}

QString Client_Name;
QString Client_FirstName;
int Client_ID;
QString Client_Birthday;
int Client_Telephone;
ClientDB cldb;
CarDB crdb;
int i;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    ClientDB cldb;
    CarDB crdb;
    return a.exec();
}


