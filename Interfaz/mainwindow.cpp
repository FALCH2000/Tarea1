//
// Created by fatima on 8/31/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

void MainWindow::setWidgetTable() {

    QStringList titulosH;

    //titulosH <<"p1"<<"p2"<<"d1"<<"p3"<<"d2"<<"d3"<<"d4"<<"p4"<<"d5"<< "d6";
    QStringList titulosV;
    titulosV << "Palabra de datos (sin paridad)";

    int counter_paridad=0;
    int counter_bits=1;

    for(int i=0; i<columns;i++){
        QString textoD= "d";
        if((i==0)||(i==1)||i==2||i==4||i==8||i==16){
            QString paridad="p";
            paridad.append(QString::number(counter_paridad));
            titulosH.append(paridad);
            titulosV.append(paridad);
            counter_paridad++;
        }else{
            textoD.append(QString::number(counter_bits));
            counter_bits++;
            titulosH.append(textoD);
        }
    }
    titulosV.append("Palabra de datos (con paridad)");


    ui->tableWidget->setColumnCount(columns);
    ui->tableWidget->setHorizontalHeaderLabels(titulosH);
    ui->tableWidget->setRowCount(rows+2);
    ui->tableWidget->setVerticalHeaderLabels(titulosV);


    //-------------------------------Tabla 2-----------------------------------------------
    QStringList titulosH_2;
    QStringList titulosV_2;
    titulosV_2 << "Palabra de datos recibida";
    counter_paridad=0;
    counter_bits=1;
    for(int i=0; i<columns;i++){
        QString textoD= "d";
        if((i==0)||(i==1)||i==2||i==4||i==8||i==16){
            QString paridad="p";
            paridad.append(QString::number(counter_paridad));
            titulosH_2.append(paridad);
            titulosV_2.append(paridad);
            counter_paridad++;
        }else{
            textoD.append(QString::number(counter_bits));
            counter_bits++;
            titulosH_2.append(textoD);
        }
    }
    titulosH_2.append("Prueba de Paridad");
    titulosH_2.append("Bit de Paridad");

    ui->tableWidget_2->setColumnCount(columns+2);
    ui->tableWidget_2->setHorizontalHeaderLabels(titulosH_2);
    ui->tableWidget_2->setRowCount(rows+1);
    ui->tableWidget_2->setVerticalHeaderLabels(titulosV_2);
    llenarTabla();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    Conversiones prueba = *new Conversiones();
    QString numOctalText;
    numOctalText= ui->lineEdit->text();

    int miNumero= numOctalText.toInt();
    if(prueba.Verificar_Octal(miNumero)==1){
        string auxiliar= to_string(prueba.Octal_Decimal(miNumero));

        QString numBinario=QString::fromStdString(prueba.Octal_Binario(miNumero));

        QString numDecimal=QString::fromStdString(auxiliar);
        QString numHexadecimal=QString::fromStdString(prueba.Octal_Hexadecimal(miNumero));
        ui->label_5->setText(numBinario);
        ui->label_7->setText(numDecimal);
        ui->label_9->setText(numHexadecimal);
        crearHamming();
        this->numeroBinario= numBinario.toStdString();
        if(ui->label_2->text()=="IMPAR")
            hamming->cambiarTipoParidad(); //Cambia el tipo de paridad
        generarHamming(numeroBinario);
        setWidgetTable();
    }else{
        QMessageBox::information(this, "Mensaje", "El numero ingresado no es octal");
    }
}

void MainWindow::on_pushButton_clicked() {
    QString labelText= ui->label_2->text();
    if(labelText=="PAR"){
        ui->label_2->setText("IMPAR");
    }else{
        ui->label_2->setText("PAR");
    }
}
void MainWindow::on_pushButton_3_clicked() {
//    -----------------------Para mostrar el grafico NRZI -------------------------------
//     el numero esta guardando en la variable string numeroBinario
    mostrarGrafico(numeroBinario);
}
void MainWindow::on_tableWidget_2_cellClicked(int row, int column)
{
    if(row==0){
        originalVec = hamming->establecerValoresDeParidad(originalVec);
        if(ui->tableWidget_2->item(row,column)->text()=="1"){
            ui->tableWidget_2->setItem(0, column, new QTableWidgetItem("0"));
        }else
            ui->tableWidget_2->setItem(0, column, new QTableWidgetItem("1"));

        originalVec =hamming->modificarBitEnPos(originalVec, column);

        std::vector<int> posBitsParidad = hamming->posDeBitsDeParidad(originalVec);
        hamming->print(originalVec);
        std::cout << "Alterar un bit:" << std::endl;
        hamming->print(originalVec);
        int posError = hamming->seekError(originalVec);
        std::cout << "Error en posición: " << posError << std::endl;

        for(int i=0; i <= rows; i++){
            std::vector<int> posBitsQueVerifica = hamming->posQueVerificaUnBitDeParidad(originalVec, posBitsParidad[i]);
            int sizeVec= posBitsQueVerifica.size();
            for(int j=0; j<columns;j++){
                for(int k=0; k<sizeVec; k++){
                    if(j==posBitsQueVerifica[k]){
                        bool item=originalVec[j];
                        ui->tableWidget_2->setItem(i+1, j, new QTableWidgetItem(QString::number(item)));
                    }
                }
                if(j==std::pow(2,i)){
                    bool item=originalVec[j];
                    ui->tableWidget_2->setItem(i+2, j, new QTableWidgetItem(QString::number(item)));
                }
            }
        }
        //-------------------------- Llenar tabla 2 segunda parte-----------------------
        if(ui->label_2->text()=="PAR"){
            ui->tableWidget_2->setItem(0, ui->tableWidget_2->columnCount()-2, new QTableWidgetItem("0"));
        }else{
            ui->tableWidget_2->setItem(0, ui->tableWidget_2->columnCount()-2, new QTableWidgetItem("1"));
        }

        std::vector<int> posBitsError = hamming->bitsDeParidadQueDetectanError(originalVec);

        for(int i=1; i<=rows;i++){
            for(int j=0; j<posBitsError.size();j++){
                if(i==posBitsError[j]){
                    ui->tableWidget_2->setItem(i, ui->tableWidget_2->columnCount()-2, new QTableWidgetItem("ERROR"));
                    break;
                }else
                    ui->tableWidget_2->setItem(i, ui->tableWidget_2->columnCount()-2, new QTableWidgetItem("Correcto"));
            }
        }
        //Llenar ultima columna

        int columnVal=1;
        for(int i=0;i<rows-1;i++){
            int counter=0;
            for(int k=0;k<=i;k++) {
                columnVal = std::pow(2, counter);
                counter++;
            }
            std::cout<<i<<" Val columna "<<columnVal<<std::endl;
            QString qs= ui->tableWidget->item(i+2,columnVal)->text();

            ui->tableWidget_2->setItem(i+2,ui->tableWidget_2->columnCount()-1,new QTableWidgetItem(qs));
        }
    }

}
vector <bool> MainWindow::convertirArreglo(int x) {
    vector<bool> resultArray;
    while (true)
    {
        resultArray.insert(resultArray.begin(), x%10);
        x /= 10;
        if(x == 0)
            return resultArray;
    }
}

void MainWindow::crearHamming() {
    hamming=new Hamming;
}

void MainWindow::generarHamming(string x) {
    //std::vector<bool> vec{1, 1, 1,0};
    //std::vector<bool> vec{0, 1, 1,0,1,0,1};
    int a = stoi(x, nullptr, 10);
    std::vector<bool> vec=convertirArreglo(a);
    /*
    std::cout<<"---numero Binario---"<<a<<" y string"<<x<<std::endl;
    std::cout<<"---ARREGLO---"<<std::endl;
    for (int i : resultArray)
        std::cout << i << ' ';
    std::cout<<""<<std::endl;
    std::cout<<"---End---"<<std::endl;

    std::cout<<"---VUELVE A LA FUNCION---"<<std::endl;
    */
    hamming->print(vec);
    vec = hamming->agregarBitsDeParidad(vec);
    std::cout << "Agregar los bits de paridad (no tienen ningún valor):" << std::endl;
    hamming->print(vec);
    vec = hamming->establecerValoresDeParidad(vec);
    std::cout << "Establecer el valor de los bits de paridad:" << std::endl;
    hamming->print(vec);

    originalVec= vec;
    /*
    vec = hamming->modificarBitEnPos(vec, 2);
    std::cout << "Alterar un bit:" << std::endl;
    hamming->print(vec);
    int posError = hamming->seekError(vec);
    std::cout << "Error en posición: " << posError << std::endl;
    std::cout << "------ Pa las tablas ------" << std::endl;
*/
    std::vector<int> posBitsParidad = hamming->posDeBitsDeParidad(vec);
    std::cout << "Posiciones de los bits de paridad:" << std::endl;

    rows= posBitsParidad.size();
    columns= vec.size();
    /*
    for (int &i: posBitsParidad)
        std::cout << i << ' ';
    std::cout << "" << std::endl;
    std::vector<int> posBitsQueVerifica = hamming->posQueVerificaUnBitDeParidad(vec, 2);
    std::cout << "Posiciones que verfica el bit de paridad en pos 2" << std::endl;
    for (int &i: posBitsQueVerifica)
        std::cout << i << ' ';
    std::cout << "" << std::endl; */

}

void MainWindow::llenarTabla() {
    //-----------------------------------Llenar tabla 1--------------------------
    //
    int rowsAux= ui->tableWidget->rowCount();
    for(int i=0; i<columns;i++){
        if(!((i==0)||(i==1)||i==2||i==4||i==8||i==16)){
            bool item=originalVec[i];
            ui->tableWidget->setItem(0, i, new QTableWidgetItem(QString::number(item)));
        }
        bool item=originalVec[i];

        ui->tableWidget->setItem(rowsAux-1, i, new QTableWidgetItem(QString::number(item)));
        ui->tableWidget_2->setItem(0, i, new QTableWidgetItem(QString::number(item)));
    }

    std::vector<int> posBitsParidad = hamming->posDeBitsDeParidad(originalVec);
    for(int i=0; i <= rows; i++){
        std::vector<int> posBitsQueVerifica = hamming->posQueVerificaUnBitDeParidad(originalVec, posBitsParidad[i]);
        int sizeVec= posBitsQueVerifica.size();
        for(int j=0; j<columns;j++){
            for(int k=0; k<sizeVec; k++){
                if(j==posBitsQueVerifica[k]){
                    bool item=originalVec[j];
                    ui->tableWidget->setItem(i+1, j, new QTableWidgetItem(QString::number(item)));
                }
            }
            if(j==std::pow(2,i)){
                bool item=originalVec[j];
                ui->tableWidget->setItem(i+2, j, new QTableWidgetItem(QString::number(item)));
            }
        }
    }
}




