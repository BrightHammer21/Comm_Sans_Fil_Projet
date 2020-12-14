#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void identifier();
    void lectureDonneesCartes();

private slots:
    void on_pushButton_clicked();

    void on_connect_clicked();

    void on_formater_clicked();

    void on_btn_valider_infos_clicked();

    void on_btn_valider_increment_decrement_clicked();




private:
    Ui::Widget *ui;
    bool carteConnectee;
    QTimer *timer;

    //LISTE DES CLES
    uint8_t key_A[6] = {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5} ;
    uint8_t key_B[6] = {0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5} ;


    uint8_t key_A2[6] = {0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5} ;
    uint8_t key_B2[6] = {0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5} ;

    uint8_t key_F[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} ;

    void btn_cliquable(bool boulean);


};
#endif // WIDGET_H
