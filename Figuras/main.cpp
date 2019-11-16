/*
Programa con funciones:
    Ejercicios de triángulos, polígonos y arcos” permita especificar una serie de transformaciones (rotación, traslación, zoom out/in y reflexión
    Sacada de las presentaciones de la clase:
        https://evileg.com/en/post/82/
        https://stackoverflow.com/questions/17375808/qt-drawing-a-circle
        www.github.com
        geeksforgeeks.com 
        
*/


#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();

    return a.exec();
}
