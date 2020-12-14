//#pragma comment(lib, "ODALID.lib")
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QtGui>
#include "ODALID.h"

Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    btn_cliquable(false);


    //--------------------Initialisation du timer et connection au slot
    qDebug()<<"INITIALISATION";
    carteConnectee=false;

    timer = new QTimer(this);
    timer->setTimerType(Qt::CoarseTimer);

    connect(timer, SIGNAL(timout()), this, SLOT(identifier()));
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

     ui->connect->setEnabled(false);
     timer->start(10);

     identifier();

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

    uint8_t atq[2];  //réponse à la requête
    uint8_t sak[1];  //select acknowledge
    uint8_t uid[12]; //identifiant unique
    uint16_t uid_len = 12;


    qDebug() << "Identification de la carte : ";

    //On regarde si la carte est toujours sur le lecteur
    status = ISO14443_3_A_PollCard(&MonLecteur, atq, sak, uid, &uid_len);


    if(carteConnectee) //On déactive tout si la carte n'est pas présente
    {

        //Si la carte n'est plus sur le lecteur
        if(status!=0)
        {
            carteConnectee = false;
            LEDBuzzer(&MonLecteur, LED_GREEN_OFF);
            LEDBuzzer(&MonLecteur, LED_YELLOW_ON); //On affiche un voyant jaune pour signaler qu'il manque la carte
            qDebug() << "Aucune carte détectée.";
            btn_cliquable(false);
        }

    }
    else //si carte connectée, mise à jour
    {
        //activer les champs RF pour un temps indéterminé
        RF_Power_Control(&MonLecteur, TRUE, 0);

        if(status!= 0)
        {
            ui->Affichage->setText("Carte Mifare non connectée");
            ui->Affichage->update();
        }
        else
        {
            carteConnectee = true;
            LEDBuzzer(&MonLecteur, LED_GREEN_ON);
            btn_cliquable(true);

            qDebug() << "UID trouvé : ";
            for(int i=0; i<uid_len; i++)
            {
                qDebug() << uid[i];
            }

            qDebug()<< "ATQ = " << atq[1] << atq[0] << "\nSAK = " << sak[0]<<"\n";

            ui->Affichage->setText("Carte Mifare connectée");
            ui->Affichage->update();

            lectureDonneesCartes();
        }
    }

}

void Widget::lectureDonneesCartes()
{
    int16_t status;
    uint8_t nom[16] = {'-'};
    uint8_t prenom[16] = {'-'};
    uint32_t monCredit=0;


    status = Mf_Classic_Read_Block(&MonLecteur, TRUE, 10, nom, TRUE, 2);
    if(status!=0)
    {
        qDebug() << "Erreur : " << GetErrorMessage(status);
    }

    status = Mf_Classic_Read_Block(&MonLecteur, TRUE, 9, prenom, TRUE, 2);
    if(status!=0)
    {
        qDebug() << "Erreur :" << GetErrorMessage(status);
    }


    //affichage dans la fenetre
    ui->Nom->setText(QString((const char*)nom));
    ui->Prenom->setText(QString((const char*)prenom));

    //lecture du crédit
    status = Mf_Classic_Read_Value(&MonLecteur, TRUE, 14, &monCredit, TRUE, 3);
    ui->credit->setText(QString("%1").arg(monCredit));

}

void Widget::btn_cliquable(bool boolean)
{
     ui->formater->setEnabled(boolean);
     ui->btn_valider_increment_decrement->setEnabled(boolean);
     ui->btn_valider_infos->setEnabled(boolean);
}

//////////////////////////////////////////////////////CHANGER NOM PRENOM CREDIT
void Widget::on_btn_valider_infos_clicked()
{
    int16_t status = 0;

    status = Mf_Classic_UpdadeAccessBlock(&MonLecteur, TRUE,2,0,key_A,key_B,ACC_BLOCK_READWRITE,ACC_BLOCK_READWRITE,ACC_BLOCK_READWRITE,ACC_AUTH_NORMAL,TRUE);




}

void Widget::on_formater_clicked()
{

}



void Widget::on_btn_valider_increment_decrement_clicked()
{

}
