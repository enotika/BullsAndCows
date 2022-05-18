#ifndef RECORDS_H
#define RECORDS_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include "game.h"
namespace Ui {
class Records;
}

class Records : public QMainWindow
{
    Q_OBJECT

public:
    QTableWidgetItem* tableCell = new QTableWidgetItem;
    explicit Records(QWidget *parent = nullptr);
    //Records(QWidget *parent = nullptr, std::set<std::pair<int, std::string>> arecs = {});
    ~Records();
    void showRecords();

private:
    Ui::Records *ui;
};

#endif // RECORDS_H
