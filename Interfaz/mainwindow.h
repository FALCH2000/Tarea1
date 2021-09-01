//
// Created by fatima on 8/31/21.
//

#ifndef TAREA_1_MAINWINDOW_H
#define TAREA_1_MAINWINDOW_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QWidget {
    Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);

    ~mainwindow() override;

private:
    Ui::mainwindow *ui;
};


#endif //TAREA_1_MAINWINDOW_H
