#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QTableWidget"
#include "records.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btNewGame_clicked();

    void on_inputNumber_returnPressed();

    void on_checkBut_clicked();

    void on_showRecords_clicked();

private:
    int ds;
    QTableWidgetItem* tableCell = new QTableWidgetItem;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
