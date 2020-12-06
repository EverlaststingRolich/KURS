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

    currClassIsItem = true;
    ui->volume_edit->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_add_clicked()
{
    if (currClassIsItem)
    {
        std:: string owner = ui->owner_edit->text().toStdString();
        std:: string dest = ui->dest_edit->text().toStdString();
        int weight  = atoi(ui->weight_edit->text().toStdString().c_str());
        auto la = new luggage(owner, dest, weight);
        cout << "test2: " << la->get_owner() << endl;
        if(weight <= 0)
            QMessageBox::critical(this, "Add", "Wrong data. Please, try again");
        else
        {
            this->cargo_collection.add_elem(*la);
        }
        ui->tableWidget->setRowCount(0);

        for (int i = 0; i < cargo_collection.get_size(); i++)
        {
            ui->tableWidget->insertRow(i);

            QTableWidgetItem *ownerItem = new QTableWidgetItem();
            ownerItem->setText(QString::fromStdString(cargo_collection.get_iterator()[i]->get_data("owner")));
            ui->tableWidget->setItem(i, 0, ownerItem);

            QTableWidgetItem *destItem = new QTableWidgetItem();
            destItem->setText(QString::fromStdString(cargo_collection.get_iterator()[i]->get_data("dest")));
            ui->tableWidget->setItem(i, 1, destItem);

            QTableWidgetItem *weightItem = new QTableWidgetItem();
            weightItem->setText(QString::fromStdString(cargo_collection.get_iterator()[i]->get_data("weight")));
            ui->tableWidget->setItem(i, 2, weightItem);

            QTableWidgetItem *volumeItem = new QTableWidgetItem();
            volumeItem->setText(QString::fromStdString(cargo_collection.get_iterator()[i]->get_data("volume")));
            ui->tableWidget->setItem(i, 3, volumeItem);

            QTableWidgetItem *priceItem = new QTableWidgetItem();
            priceItem->setText(QString::fromStdString(cargo_collection.get_iterator()[i]->get_data("price")));
            ui->tableWidget->setItem(i, 4, priceItem);
        }
    }
    else
    {
        std:: string owner = ui->owner_edit->text().toStdString();
        std:: string dest = ui->dest_edit->text().toStdString();
        int weight  = atoi(ui->weight_edit->text().toStdString().c_str());
        int volume  = atoi(ui->volume_edit->text().toStdString().c_str());
        auto ca = new cargo(owner, dest, weight, volume);
        cout << "test: " << ca->get_owner() << endl;
        if(volume <= 0 || weight <= 0)
            QMessageBox::critical(this, "Add", "Wrong data. Please, try again");
        else
        {
            this->cargo_collection.add_elem(*ca);
        }

        ui->tableWidget->setRowCount(0);

        for (int i = 0; i < cargo_collection.get_size(); i++)
        {
            ui->tableWidget->insertRow(i);

            QTableWidgetItem *ownerItem = new QTableWidgetItem();
            ownerItem->setText(QString::fromStdString(cargo_collection.get_iterator()[i]->get_data("owner")));
            ui->tableWidget->setItem(i, 0, ownerItem);

            QTableWidgetItem *destItem = new QTableWidgetItem();
            destItem->setText(QString::fromStdString(cargo_collection.get_iterator()[i]->get_data("dest")));
            ui->tableWidget->setItem(i, 1, destItem);

            QTableWidgetItem *weightItem = new QTableWidgetItem();
            weightItem->setText(QString::fromStdString(cargo_collection.get_iterator()[i]->get_data("weight")));
            ui->tableWidget->setItem(i, 2, weightItem);

            QTableWidgetItem *volumeItem = new QTableWidgetItem();
            volumeItem->setText(QString::fromStdString(cargo_collection.get_iterator()[i]->get_data("volume")));
            ui->tableWidget->setItem(i, 3, volumeItem);

            QTableWidgetItem *priceItem = new QTableWidgetItem();
            priceItem->setText(QString::fromStdString(cargo_collection.get_iterator()[i]->get_data("price")));
            ui->tableWidget->setItem(i, 4, priceItem);
        }
    }
}




void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    ui->owner_edit->setText(QString(""));
    ui->dest_edit->setText(QString(""));
    ui->weight_edit->setText(QString(""));
    ui->volume_edit->setText(QString(""));

    if (arg1 == QString("Default luggage"))
    {
        ui->owner_edit->setEnabled(true);
        ui->dest_edit->setEnabled(true);
        ui->weight_edit->setEnabled(true);
        ui->volume_edit->setEnabled(false);
        currClassIsItem = true;
    }
    else
    {
        ui->owner_edit->setEnabled(true);
        ui->dest_edit->setEnabled(true);
        ui->weight_edit->setEnabled(true);
        ui->volume_edit->setEnabled(true);
        currClassIsItem = false;
    }
}
