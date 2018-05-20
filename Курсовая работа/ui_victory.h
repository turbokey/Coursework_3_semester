/********************************************************************************
** Form generated from reading UI file 'victory.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VICTORY_H
#define UI_VICTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Victory
{
public:
    QLabel *face;
    QLabel *mines_label;
    QPushButton *continueButton;
    QLabel *score_label;
    QLabel *new_record_label;
    QLabel *mines;
    QLabel *score;
    QLabel *victory_or_lose;

    void setupUi(QWidget *Victory)
    {
        if (Victory->objectName().isEmpty())
            Victory->setObjectName(QStringLiteral("Victory"));
        Victory->setWindowModality(Qt::NonModal);
        Victory->resize(403, 237);
        Victory->setAutoFillBackground(false);
        face = new QLabel(Victory);
        face->setObjectName(QStringLiteral("face"));
        face->setGeometry(QRect(10, 50, 150, 150));
        mines_label = new QLabel(Victory);
        mines_label->setObjectName(QStringLiteral("mines_label"));
        mines_label->setGeometry(QRect(180, 100, 161, 21));
        QFont font;
        font.setPointSize(14);
        mines_label->setFont(font);
        continueButton = new QPushButton(Victory);
        continueButton->setObjectName(QStringLiteral("continueButton"));
        continueButton->setGeometry(QRect(160, 210, 81, 23));
        QFont font1;
        font1.setPointSize(10);
        continueButton->setFont(font1);
        score_label = new QLabel(Victory);
        score_label->setObjectName(QStringLiteral("score_label"));
        score_label->setGeometry(QRect(180, 140, 161, 21));
        score_label->setFont(font);
        new_record_label = new QLabel(Victory);
        new_record_label->setObjectName(QStringLiteral("new_record_label"));
        new_record_label->setGeometry(QRect(200, 60, 181, 21));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        new_record_label->setFont(font2);
        new_record_label->setAlignment(Qt::AlignCenter);
        mines = new QLabel(Victory);
        mines->setObjectName(QStringLiteral("mines"));
        mines->setGeometry(QRect(350, 100, 41, 21));
        mines->setFont(font);
        score = new QLabel(Victory);
        score->setObjectName(QStringLiteral("score"));
        score->setGeometry(QRect(350, 140, 41, 21));
        score->setFont(font);
        victory_or_lose = new QLabel(Victory);
        victory_or_lose->setObjectName(QStringLiteral("victory_or_lose"));
        victory_or_lose->setGeometry(QRect(100, 10, 211, 31));
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setUnderline(true);
        font3.setWeight(50);
        font3.setKerning(true);
        victory_or_lose->setFont(font3);
        victory_or_lose->setAlignment(Qt::AlignCenter);

        retranslateUi(Victory);

        QMetaObject::connectSlotsByName(Victory);
    } // setupUi

    void retranslateUi(QWidget *Victory)
    {
        Victory->setWindowTitle(QApplication::translate("Victory", "Form", Q_NULLPTR));
        face->setText(QString());
        mines_label->setText(QApplication::translate("Victory", "\320\234\320\270\320\275 \320\276\320\261\320\275\320\260\321\200\321\203\320\266\320\265\320\275\320\276:", Q_NULLPTR));
        continueButton->setText(QApplication::translate("Victory", "\320\237\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\321\214", Q_NULLPTR));
        score_label->setText(QApplication::translate("Victory", "\320\236\321\207\320\272\320\276\320\262 \320\277\320\276\320\273\321\203\321\207\320\265\320\275\320\276:", Q_NULLPTR));
        new_record_label->setText(QApplication::translate("Victory", "\320\235\320\236\320\222\320\253\320\231 \320\240\320\225\320\232\320\236\320\240\320\224!", Q_NULLPTR));
        mines->setText(QString());
        score->setText(QString());
        victory_or_lose->setText(QApplication::translate("Victory", "\320\232\320\276\320\275\320\265\321\206 \320\270\320\263\321\200\321\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Victory: public Ui_Victory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VICTORY_H
