/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *connect;
    QTextEdit *Affichage;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *formater;
    QPushButton *btn_valider_increment_decrement;
    QPushButton *btn_valider_infos;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *estConnecte;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        connect = new QPushButton(Widget);
        connect->setObjectName(QString::fromUtf8("connect"));
        connect->setGeometry(QRect(80, 200, 171, 31));
        QFont font;
        font.setPointSize(16);
        connect->setFont(font);
        Affichage = new QTextEdit(Widget);
        Affichage->setObjectName(QString::fromUtf8("Affichage"));
        Affichage->setGeometry(QRect(60, 130, 211, 51));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(230, 500, 211, 61));
        pushButton->setFont(font);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 20, 311, 51));
        label->setFont(font);
        formater = new QPushButton(Widget);
        formater->setObjectName(QString::fromUtf8("formater"));
        formater->setGeometry(QRect(270, 410, 91, 31));
        formater->setFont(font);
        btn_valider_increment_decrement = new QPushButton(Widget);
        btn_valider_increment_decrement->setObjectName(QString::fromUtf8("btn_valider_increment_decrement"));
        btn_valider_increment_decrement->setGeometry(QRect(70, 380, 75, 23));
        btn_valider_increment_decrement->setFont(font);
        btn_valider_infos = new QPushButton(Widget);
        btn_valider_infos->setObjectName(QString::fromUtf8("btn_valider_infos"));
        btn_valider_infos->setGeometry(QRect(434, 210, 75, 23));
        btn_valider_infos->setFont(font);
        horizontalSlider = new QSlider(Widget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(30, 330, 160, 16));
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 360, 47, 13));
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(474, 130, 113, 20));
        lineEdit_2 = new QLineEdit(Widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(474, 170, 113, 20));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(380, 130, 81, 20));
        label_3->setFont(font);
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(380, 170, 81, 20));
        label_4->setFont(font);
        estConnecte = new QPushButton(Widget);
        estConnecte->setObjectName(QString::fromUtf8("estConnecte"));
        estConnecte->setGeometry(QRect(560, 30, 75, 23));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        connect->setText(QCoreApplication::translate("Widget", "Connect", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "Quitter", nullptr));
        label->setText(QCoreApplication::translate("Widget", "CONNECTEUR DE CARTE", nullptr));
        formater->setText(QCoreApplication::translate("Widget", "Formater", nullptr));
        btn_valider_increment_decrement->setText(QCoreApplication::translate("Widget", "Valider", nullptr));
        btn_valider_infos->setText(QCoreApplication::translate("Widget", "Valider", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "0", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "Nom :", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "Pr\303\251nom :", nullptr));
        estConnecte->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
