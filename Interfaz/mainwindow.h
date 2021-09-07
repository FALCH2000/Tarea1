//
// Created by fatima on 8/31/21.
//

#ifndef TAREA_1_MAINWINDOW_H
#define TAREA_1_MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QString>
#include <iostream>
#include "../Conversiones/Conversiones.h"
#include <QMessageBox>
#include "../HammingCode/Hamming.h"
//#include "../Gráfico/GraficoNRZI.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setWidgetTable();
    void crearHamming();
    void generarHamming(string x);
    void llenarTabla();
    vector<bool> convertirArreglo(int x);

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_tableWidget_2_cellClicked(int row, int column);
    void on_pushButton_3_clicked();


private:
    Ui::MainWindow *ui;
    Hamming *hamming;
    int columns;
    int rows;
    std::vector<bool> originalVec;
    string numeroBinario;

};



#endif //TAREA_1_MAINWINDOW_H
