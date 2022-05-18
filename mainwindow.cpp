#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"
#include "records.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QFile>
#include <QTextStream>
Game gm;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->table->setEditTriggers(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btNewGame_clicked()
{
    for(int i = ui->table->rowCount() - 1; i >= 0; i--){
        ui->table->removeRow(i);
    }
    gm.startGame();
}

void MainWindow::on_inputNumber_returnPressed()
{
    std::string text = ui->inputNumber->text().toStdString();
    if(!gm.goodString(text)){
        QMessageBox::warning(this, "Error", "Неправильный ввод, попытайтесь ещё");
        return;
    }
    gm.setGiven(text);
    ui->inputNumber->clear();
    if(gm.isFinished()){
        bool ok;
        QString name = QInputDialog::getText(this, "Сохранить рекорд", "Имя: ", QLineEdit::Normal, "", &ok);
        if(ok){
            std::string aName = name.toStdString();
            gm.saveRecord(aName);
        }
        if (QMessageBox::question(this, "Игра закончена!", "Победа! Желаете сыграть снова?", QMessageBox::Yes | QMessageBox::No) == QMessageBox::No){
            QApplication::quit();
        } else {
            for(int i = ui->table->rowCount() - 1; i >= 0; i--){
                ui->table->removeRow(i);
            }
            gm.startGame();
        }
        return;
    }
    std::pair<int, int > answer = gm.check();

    ui->table->insertRow(ui->table->rowCount());

    QTableWidgetItem* item = new QTableWidgetItem(*tableCell);
    QTableWidgetItem* item2 = new QTableWidgetItem(*tableCell);
    item->setText(QString::fromStdString(text));
    ui->table->setItem(ui->table->rowCount() - 1, 0, item);
    std::string dop = "Коровы: ";
    dop += std::to_string(answer.first);
    dop += " Быки: ";
    dop += std::to_string(answer.second);
    item2->setText(QString::fromStdString(dop));
    ui->table->setItem(ui->table->rowCount() - 1, 1, item2);
}




void MainWindow::on_checkBut_clicked()
{
    std::string text = ui->inputNumber->text().toStdString();
    if(!gm.goodString(text)){
        QMessageBox::warning(this, "Error", "Неправильный ввод, попытайтесь ещё");
        return;
    }
    gm.setGiven(text);
    ui->inputNumber->clear();
    if(gm.isFinished()){
        bool ok;
        QString name = QInputDialog::getText(this, "Сохранить рекорд", "Имя: ", QLineEdit::Normal, "", &ok);
        if(ok){
            std::string aName = name.toStdString();
            gm.saveRecord(aName);
        }
        if (QMessageBox::question(this, "Игра закончена!", "Победа! Желаете сыграть снова?", QMessageBox::Yes | QMessageBox::No) == QMessageBox::No){
            QApplication::quit();
        } else {
            for(int i = ui->table->rowCount() - 1; i >= 0; i--){
                ui->table->removeRow(i);
            }
            gm.startGame();
        }
        return;
    }
    std::pair<int, int > answer = gm.check();

    ui->table->insertRow(ui->table->rowCount());
    QTableWidgetItem* item = new QTableWidgetItem(*tableCell);
    QTableWidgetItem* item2 = new QTableWidgetItem(*tableCell);
    item->setText(QString::fromStdString(text));
    ui->table->setItem(ui->table->rowCount() - 1, 0, item);
    std::string dop = "Коровы: ";
    dop += std::to_string(answer.first);
    dop += " Быки: ";
    dop += std::to_string(answer.second);
    item2->setText(QString::fromStdString(dop));
    ui->table->setItem(ui->table->rowCount() - 1, 1, item2);
}

void MainWindow::on_showRecords_clicked()
{
    QFile mFile("save.txt");
    mFile.open(QIODevice::WriteOnly);
    QTextStream writeStream(&mFile);
    for(auto to: gm.rec){
        writeStream << QString::fromStdString(to.second) << ' ' << QString::number(to.first) << '\n';
    }
    mFile.close();
    Records *recWin;
    recWin = new Records();
    recWin->show();
    //this->close();
}
