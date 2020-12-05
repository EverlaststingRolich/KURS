#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "cargo.h"
#include <string>
#include <fstream>
#include <stdlib.h>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    std:: string owner = ui->owner->text().toStdString();
    std:: string dest = ui->dest->text().toStdString();
    int weight  = atoi(ui->weight->text().toStdString().c_str());
    int volume  = atoi(ui->volume->text().toStdString().c_str());
    auto ca = new cargo(owner, dest, weight, volume);
    cout << "test: " << ca->get_owner() << endl;
    if(volume <= 0 || weight <= 0)
        QMessageBox::critical(this, "Add", "Wrong data. Please, try again");
    else
    {
        this->cargo_collection.add_elem(*ca);
        QMessageBox::information(this, "Add", "You add new purchase");
    }

    for (int i = 0; i < cargo_collection.get_size(); i++)
    {
        ui->tableWidget->insertRow(i);

    }

}
