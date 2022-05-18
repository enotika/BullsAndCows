#include "records.h"
#include "ui_records.h"
#include "game.h"
#include <QFile>
Records::Records(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Records)
{
    ui->setupUi(this);
    ui->recTable->setEditTriggers(0);
    showRecords();
}


Records::~Records()
{
    delete ui;
}

void Records::showRecords()
{
    QFile mFile("save.txt");
    mFile.open(QIODevice::ReadOnly | QIODevice::Text);
    std::vector<std::pair<std::string, std::string > > vec;
    while(!mFile.atEnd()){
        QString line = mFile.readLine();
        std::string name = "";
        std::string res = "";
        std::string strLine = line.toStdString();
        bool nameFinished = false;
        for(int i = 0; i < strLine.size(); i++){
            if(strLine[i] == ' '){
                nameFinished = true;
                continue;
            }
            if(!nameFinished){
                name += strLine[i];
            } else {
                res += strLine[i];
            }
        }
        vec.push_back({name, res});
    }
    for(auto to : vec){
        ui->recTable->insertRow(ui->recTable->rowCount());
        QTableWidgetItem* item = new QTableWidgetItem(*tableCell);
        QTableWidgetItem* item2 = new QTableWidgetItem(*tableCell);
        item->setText(QString::fromStdString(to.first));
        ui->recTable->setItem(ui->recTable->rowCount() - 1, 0, item);
        item2->setText(QString::fromStdString(to.second));
        ui->recTable->setItem(ui->recTable->rowCount() - 1, 1, item2);
    }
}
