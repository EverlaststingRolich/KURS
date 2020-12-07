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


//Добавление элементов
void MainWindow::on_add_clicked()
{
    if (currClassIsItem)
    {
        std:: string owner = ui->owner_edit->text().toStdString();
        std:: string dest = ui->dest_edit->text().toStdString();
        int weight  = atoi(ui->weight_edit->text().toStdString().c_str());
        auto la = new luggage(owner, dest, weight);
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
    ui->setButton->setEnabled(false);
    ui->delButton->setEnabled(false);
}



//изменение класса
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


//Полная очистка таблицы
void MainWindow::on_clear_clicked()
{
    if (this->cargo_collection.get_iterator() && this->cargo_collection.get_size())
    {
        this->cargo_collection.clear();
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
        QMessageBox::critical(this,"Clear", "There is no data to clean");
}

//Выдиление ряда в таблице
void MainWindow::on_tableWidget_cellClicked(int row)
{
    ui->setButton->setEnabled(true);
    ui->delButton->setEnabled(true);

    selectedRowIndex = row;
}

//Удаление выделенной строки
void MainWindow::on_delButton_clicked()
{
    if (ui->tableWidget->selectedItems().empty())
        return;

    cargo_collection.remove(selectedRowIndex);

    ui->tableWidget->removeRow(selectedRowIndex);
    selectedRowIndex = -1;

    ui->owner_edit->clear();
    ui->dest_edit->clear();
    ui->weight_edit->clear();
    ui->volume_edit->clear();

    ui->setButton->setEnabled(false);
    ui->delButton->setEnabled(false);
}

//Изменение выделенной строки
void MainWindow::on_setButton_clicked()
{
    if (ui->tableWidget->selectedItems().empty())
        return;

    if (currClassIsItem)
    {
        std:: string owner = ui->owner_edit->text().toStdString();
        std:: string dest = ui->dest_edit->text().toStdString();
        int weight  = atoi(ui->weight_edit->text().toStdString().c_str());
        if (owner != "" || dest != "" || weight > 1)
        {
            auto lu = new luggage(owner, dest, weight);
            cargo_collection.remove(selectedRowIndex);
            cargo_collection.add_elem(*lu);

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
            QMessageBox::critical(this, "Set", "Wrong data. Please, try again");
    }
    else
    {
        std:: string owner = ui->owner_edit->text().toStdString();
        std:: string dest = ui->dest_edit->text().toStdString();
        int weight  = atoi(ui->weight_edit->text().toStdString().c_str());
        int volume  = atoi(ui->volume_edit->text().toStdString().c_str());
        if (owner != "" || dest != "" || weight > 0 || volume > 0)
        {
            auto carg = new cargo(owner, dest, weight, volume);
            cargo_collection.remove(selectedRowIndex);
            cargo_collection.add_elem(*carg);

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
}
//Запись в файл
void MainWindow::on_pushButton_clicked()
{
    if(this->cargo_collection.get_iterator() && this->cargo_collection.get_size())
    {
        this->cargo_collection.to_file(ui->file_edit->text().toStdString());
    }
    else
        QMessageBox::critical(this,"Output to file", "There is no list");
}

//чтение из файла
void MainWindow::on_pushButton_2_clicked()
{
    this->cargo_collection.clear();
    this->cargo_collection.from_file(ui->file_edit->text().toStdString());
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
