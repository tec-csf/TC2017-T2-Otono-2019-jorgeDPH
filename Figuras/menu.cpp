#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);
}


void Dialog::on_pushButton_clicked(){
    Poligonos poligonos;
    poligonos.setModal(true);
    poligonos.exec();
}

void Dialog::on_pushButton_2_clicked(){
    Arcos arcos;
    arcos.setModal(true);
    arcos.exec();
}

void Dialog::on_pushButton_3_clicked(){
    Cubo cubo;
    cubo.setModal(true);
    cubo.exec();
}

void Dialog::on_pushButton_4_clicked(){
    PrismaRec prismaRectangular;
    prismaRectangular.setModal(true);
    prismaRectangular.exec();
}

void Dialog::on_pushButton_5_clicked(){
    PrismaTri prismaTriangular;
    prismaTriangular.setModal(true);
    prismaTriangular.exec();
}

void Dialog::on_pushButton_6_clicked(){
    Cono cono;
    cono.setModal(true);
    cono.exec();
}
