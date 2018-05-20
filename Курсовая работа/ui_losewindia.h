/********************************************************************************
** Form generated from reading UI file 'losewindia.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOSEWINDIA_H
#define UI_LOSEWINDIA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoseWinDia
{
public:
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *LoseWinDia)
    {
        if (LoseWinDia->objectName().isEmpty())
            LoseWinDia->setObjectName(QStringLiteral("LoseWinDia"));
        LoseWinDia->resize(400, 300);
        lineEdit = new QLineEdit(LoseWinDia);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 10, 381, 251));
        lineEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lineEdit->setReadOnly(true);
        pushButton = new QPushButton(LoseWinDia);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(160, 270, 81, 23));
        QFont font;
        font.setPointSize(10);
        pushButton->setFont(font);

        retranslateUi(LoseWinDia);

        QMetaObject::connectSlotsByName(LoseWinDia);
    } // setupUi

    void retranslateUi(QWidget *LoseWinDia)
    {
        LoseWinDia->setWindowTitle(QApplication::translate("LoseWinDia", "Form", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("LoseWinDia", "\320\227\320\264\320\265\321\201\321\214 \320\264\320\276\320\273\320\266\320\275\321\213 \320\261\321\213\321\202\321\214 \321\201\320\262\320\265\320\264\320\265\320\275\320\270\321\217 \320\276\320\261 \320\270\320\263\321\200\320\265", Q_NULLPTR));
        pushButton->setText(QApplication::translate("LoseWinDia", "\320\237\320\276\320\275\321\217\321\202\320\275\320\276", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoseWinDia: public Ui_LoseWinDia {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOSEWINDIA_H
