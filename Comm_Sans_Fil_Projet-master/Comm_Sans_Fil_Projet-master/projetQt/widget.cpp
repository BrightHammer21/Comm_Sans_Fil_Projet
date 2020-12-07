//#pragma comment(lib, "ODALID.lib")
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
    btn_cliquable(false);
}


Widget::~Widget()
{
    delete ui;
}

ReaderName MonLecteur;
char pszHost[] = "192.168.1.4";

//CONNNEXION AU LECTEUR
void Widget::on_connect_clicked()
{
    uint16_t status = 0;

     MonLecteur.Type = ReaderCDC;
     MonLecteur.device = 0;
     status = OpenCOM(&MonLecteur);



     if(status != 0)
     {
          qDebug() <<  GetErrorMessage(status);
     }
     else {
          LEDBuzzer(&MonLecteur, LED_GREEN_ON);
     }


     //VERSION
     char version[30];
     uint8_t serial[4];
     char stackReader[20];

     status = Version(&MonLecteur, version, serial, stackReader);

     ui->Affichage->setText(version);
     ui->Affichage->update();

     //AFFICHAGE DU STATUT CLE
     uint16_t etat =0;

     etat = Mf_Classic_LoadKey(&MonLecteur, Auth_KeyA, key_A, 2);
     qDebug() << "Etat : " << etat;


     etat = Mf_Classic_LoadKey(&MonLecteur, Auth_KeyB, key_B, 2);
     qDebug() << "Etat : " << etat;


     etat = Mf_Classic_LoadKey(&MonLecteur, Auth_KeyA, key_A2, 3);
     qDebug() << "Etat : " << etat;

     etat = Mf_Classic_LoadKey(&MonLecteur, Auth_KeyB, key_B2, 3);
     qDebug() << "Etat : " << etat;


     etat = Mf_Classic_LoadKey(&MonLecteur, Auth_KeyA, key_F, 0);
     qDebug() << "Etat : " << etat;

     etat = Mf_Classic_LoadKey(&MonLecteur, Auth_KeyB, key_F, 0);
     qDebug() << "Etat : " << etat;

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


void Widget::identifier()
{
    uint16_t status;

    uint8_t atq[2];
    uint8_t sak[1];
    uint8_t uid[12];
    uint16_t uid_len = 12;


    //On regarde si la carte est toujours sur le lecteur
    status = ISO14443_3_A_PollCard(&MonLecteur, atq, sak, uid, &uid_len);

    //Si la carte n'est plus sur le lecteur
    if(status!=0)
    {
        carteConnectee =1;
        LEDBuzzer(&MonLecteur, LED_GREEN_OFF);
        LEDBuzzer(&MonLecteur, LED_YELLOW_ON); //On affiche un voyant jaune pour signaler qu'il manque la carte
        qDebug() << "Aucune carte détectée.";
        btn_cliquable(false);

    }
    else
    {
        carteConnectee=0;
        LEDBuzzer(&MonLecteur, LED_GREEN_ON);
        btn_cliquable(true);
    }


}

void Widget::btn_cliquable(bool boolean)
{
     ui->formater->setEnabled(boolean);
     ui->btn_valider_increment_decrement->setEnabled(boolean);
     ui->btn_valider_infos->setEnabled(boolean);
}

void Widget::on_formater_clicked()
{

}

void Widget::on_btn_valider_infos_clicked()
{

}

void Widget::on_btn_valider_increment_decrement_clicked()
{

}
