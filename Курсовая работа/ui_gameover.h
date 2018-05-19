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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Gameover
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton;

    void setupUi(QWidget *Gameover)
    {
        if (Gameover->objectName().isEmpty())
            Gameover->setObjectName(QStringLiteral("Gameover"));
        Gameover->setWindowModality(Qt::NonModal);
        Gameover->resize(300, 204);
        Gameover->setAutoFillBackground(false);
        lineEdit = new QLineEdit(Gameover);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(20, 50, 113, 20));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        lineEdit->setFont(font);
        lineEdit->setFrame(false);
        lineEdit->setReadOnly(true);
        lineEdit_2 = new QLineEdit(Gameover);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(160, 50, 113, 20));
        lineEdit_2->setFont(font);
        lineEdit_2->setFrame(false);
        lineEdit_2->setReadOnly(true);
        lineEdit_3 = new QLineEdit(Gameover);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(20, 90, 113, 20));
        lineEdit_3->setFont(font);
        lineEdit_3->setFrame(false);
        lineEdit_3->setReadOnly(true);
        lineEdit_4 = new QLineEdit(Gameover);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(160, 90, 113, 20));
        lineEdit_4->setFont(font);
        lineEdit_4->setCursor(QCursor(Qt::IBeamCursor));
        lineEdit_4->setFrame(false);
        lineEdit_4->setReadOnly(true);
        pushButton = new QPushButton(Gameover);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(110, 150, 75, 23));

        retranslateUi(Gameover);

        QMetaObject::connectSlotsByName(Gameover);
    } // setupUi

    void retranslateUi(QWidget *Gameover)
    {
        Gameover->setWindowTitle(QApplication::translate("Gameover", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Gameover", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Gameover: public Ui_Gameover {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVER_H
