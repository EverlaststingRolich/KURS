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

private:
    collection cargo_collection;
    Ui::MainWindow *ui;

    bool currClassIsItem;
};
#endif // MAINWINDOW_H
