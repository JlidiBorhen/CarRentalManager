#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "ClientDB.h"
#include "CarDB.h"
#include "Car.h"
#include "Client.h"
namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    friend void ClientDB::addClient(QString, QString, int, QString, int);
    QString Client_Name;
    QString Client_FirstName;
    int Client_ID;
    QString Client_Birthday;
    int Client_Telephone;
    ClientDB cldb;
    CarDB crdb;
    friend int main(int argc, char *argv[]);
private slots:
    void on_Rent_Car_Button_clicked();
    void on_Return_Car_Button_clicked();
    void on_Car_Add_clicked();
    void on_Car_Remove_clicked();
    void updateCars();
    void updateClients();
    void on_Search_button_clicked();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
