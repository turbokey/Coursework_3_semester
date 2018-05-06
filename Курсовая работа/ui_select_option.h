/********************************************************************************
** Form generated from reading UI file 'select_option.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECT_OPTION_H
#define UI_SELECT_OPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Select_Option
{
public:
    QPushButton *pushButton_OK;
    QPushButton *pushButton_cancel;
    QLineEdit *lineEdit_row;
    QLineEdit *lineEdit_col;
    QLineEdit *lineEdit_mine;

    void setupUi(QWidget *Select_Option)
    {
        if (Select_Option->objectName().isEmpty())
            Select_Option->setObjectName(QStringLiteral("Select_Option"));
        Select_Option->resize(400, 300);
        pushButton_OK = new QPushButton(Select_Option);
        pushButton_OK->setObjectName(QStringLiteral("pushButton_OK"));
        pushButton_OK->setGeometry(QRect(280, 240, 75, 23));
        pushButton_cancel = new QPushButton(Select_Option);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(190, 240, 75, 23));
        lineEdit_row = new QLineEdit(Select_Option);
        lineEdit_row->setObjectName(QStringLiteral("lineEdit_row"));
        lineEdit_row->setGeometry(QRect(50, 30, 113, 20));
        lineEdit_col = new QLineEdit(Select_Option);
        lineEdit_col->setObjectName(QStringLiteral("lineEdit_col"));
        lineEdit_col->setGeometry(QRect(50, 70, 113, 20));
        lineEdit_mine = new QLineEdit(Select_Option);
        lineEdit_mine->setObjectName(QStringLiteral("lineEdit_mine"));
        lineEdit_mine->setGeometry(QRect(50, 120, 113, 20));

        retranslateUi(Select_Option);

        QMetaObject::connectSlotsByName(Select_Option);
    } // setupUi

    void retranslateUi(QWidget *Select_Option)
    {
        Select_Option->setWindowTitle(QApplication::translate("Select_Option", "Form", Q_NULLPTR));
        pushButton_OK->setText(QApplication::translate("Select_Option", "OK", Q_NULLPTR));
        pushButton_cancel->setText(QApplication::translate("Select_Option", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Select_Option: public Ui_Select_Option {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECT_OPTION_H
