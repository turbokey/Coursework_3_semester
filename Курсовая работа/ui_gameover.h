/********************************************************************************
** Form generated from reading UI file 'gameover.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOVER_H
#define UI_GAMEOVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Gameover
{
public:
    QLabel *face;
    QLabel *mines_label;
    QPushButton *continueButton;
    QLabel *mines;
    QLabel *victory_or_lose;

    void setupUi(QWidget *Gameover)
    {
        if (Gameover->objectName().isEmpty())
            Gameover->setObjectName(QStringLiteral("Gameover"));
        Gameover->setWindowModality(Qt::NonModal);
        Gameover->resize(400, 237);
        Gameover->setAutoFillBackground(false);
        face = new QLabel(Gameover);
        face->setObjectName(QStringLiteral("face"));
        face->setGeometry(QRect(10, 50, 150, 150));
        mines_label = new QLabel(Gameover);
        mines_label->setObjectName(QStringLiteral("mines_label"));
        mines_label->setGeometry(QRect(180, 100, 161, 21));
        QFont font;
        font.setPointSize(14);
        mines_label->setFont(font);
        continueButton = new QPushButton(Gameover);
        continueButton->setObjectName(QStringLiteral("continueButton"));
        continueButton->setGeometry(QRect(160, 210, 81, 23));
        QFont font1;
        font1.setPointSize(10);
        continueButton->setFont(font1);
        mines = new QLabel(Gameover);
        mines->setObjectName(QStringLiteral("mines"));
        mines->setGeometry(QRect(350, 100, 41, 21));
        mines->setFont(font);
        victory_or_lose = new QLabel(Gameover);
        victory_or_lose->setObjectName(QStringLiteral("victory_or_lose"));
        victory_or_lose->setGeometry(QRect(100, 10, 211, 31));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setUnderline(true);
        font2.setWeight(50);
        font2.setKerning(true);
        victory_or_lose->setFont(font2);
        victory_or_lose->setAlignment(Qt::AlignCenter);

        retranslateUi(Gameover);

        QMetaObject::connectSlotsByName(Gameover);
    } // setupUi

    void retranslateUi(QWidget *Gameover)
    {
        Gameover->setWindowTitle(QApplication::translate("Gameover", "Form", Q_NULLPTR));
        face->setText(QString());
        mines_label->setText(QApplication::translate("Gameover", "\320\234\320\270\320\275 \320\276\320\261\320\275\320\260\321\200\321\203\320\266\320\265\320\275\320\276:", Q_NULLPTR));
        continueButton->setText(QApplication::translate("Gameover", "\320\237\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\321\214", Q_NULLPTR));
        mines->setText(QString());
        victory_or_lose->setText(QApplication::translate("Gameover", "\320\222\321\213 \320\277\321\200\320\276\320\270\320\263\321\200\320\260\320\273\320\270", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Gameover: public Ui_Gameover {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVER_H
