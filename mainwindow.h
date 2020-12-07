#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <collection.h>

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

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_add_clicked();

    void on_clear_clicked();

    void on_tableWidget_cellClicked(int row);

    void on_delButton_clicked();

    void on_setButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    collection cargo_collection;
    Ui::MainWindow *ui;

    int selectedRowIndex;
    bool currClassIsItem;
};
#endif // MAINWINDOW_H
