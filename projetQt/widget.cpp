#pragma comment(lib, "ODALID.lib")
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QtGui>
#include "ODALID.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);



}

Widget::~Widget()
{
    delete ui;
}

ReaderName MonLecteur;
char pszHost[] = "192.168.1.4";



void Widget::on_Connect_clicked()
{
    uint16_t status = 0;
     //MonLecteur.Type = ReaderTCP;
     //strcpy(MonLecteur.IPReader, pszHost);
     MonLecteur.Type = ReaderCDC;
     MonLecteur.device = 0;
     status = OpenCOM(&MonLecteur);
     qDebug() << "OpenCOM" << status;

     char version[30];
     uint8_t serial[4];
     char stackReader[20];

     status = Version(&MonLecteur, version, serial, stackReader);
     ui->Affichage->setText(version);
     ui->Affichage->update();


}

//BOUTON QUITTER
void Widget::on_pushButton_clicked()
{
     int16_t status = 0;
     RF_Power_Control(&MonLecteur, FALSE, 0);
     status = LEDBuzzer(&MonLecteur, LED_OFF);
     status = CloseCOM(&MonLecteur);
     qApp->quit();

}

void Widget::on_saisie_clicked()
{
    QString Text = ui->fenetre_saisie->toPlainText();
    qDebug() << "Text : " << Text;

}
