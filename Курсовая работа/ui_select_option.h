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
#include <QtWidgets/QSlider>
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
    QSlider *slider_row;
    QSlider *slider_col;
    QSlider *slider_mine;
    QLineEdit *row;
    QLineEdit *col;
    QLineEdit *mine;

    void setupUi(QWidget *Select_Option)
    {
        if (Select_Option->objectName().isEmpty())
            Select_Option->setObjectName(QStringLiteral("Select_Option"));
        Select_Option->resize(435, 185);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Select_Option->sizePolicy().hasHeightForWidth());
        Select_Option->setSizePolicy(sizePolicy);
        pushButton_OK = new QPushButton(Select_Option);
        pushButton_OK->setObjectName(QStringLiteral("pushButton_OK"));
        pushButton_OK->setGeometry(QRect(350, 150, 75, 23));
        QFont font;
        font.setPointSize(10);
        pushButton_OK->setFont(font);
        pushButton_cancel = new QPushButton(Select_Option);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(260, 150, 75, 23));
        pushButton_cancel->setFont(font);
        lineEdit_row = new QLineEdit(Select_Option);
        lineEdit_row->setObjectName(QStringLiteral("lineEdit_row"));
        lineEdit_row->setGeometry(QRect(10, 20, 191, 31));
        QFont font1;
        font1.setPointSize(14);
        lineEdit_row->setFont(font1);
        lineEdit_row->setMouseTracking(true);
        lineEdit_row->setFrame(false);
        lineEdit_row->setReadOnly(true);
        lineEdit_col = new QLineEdit(Select_Option);
        lineEdit_col->setObjectName(QStringLiteral("lineEdit_col"));
        lineEdit_col->setGeometry(QRect(10, 60, 191, 31));
        lineEdit_col->setFont(font1);
        lineEdit_col->setFrame(false);
        lineEdit_col->setReadOnly(true);
        lineEdit_mine = new QLineEdit(Select_Option);
        lineEdit_mine->setObjectName(QStringLiteral("lineEdit_mine"));
        lineEdit_mine->setGeometry(QRect(10, 100, 191, 31));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        lineEdit_mine->setFont(font2);
        lineEdit_mine->setFrame(false);
        lineEdit_mine->setReadOnly(true);
        slider_row = new QSlider(Select_Option);
        slider_row->setObjectName(QStringLiteral("slider_row"));
        slider_row->setGeometry(QRect(210, 30, 171, 21));
        slider_row->setMinimum(9);
        slider_row->setMaximum(19);
        slider_row->setValue(10);
        slider_row->setOrientation(Qt::Horizontal);
        slider_col = new QSlider(Select_Option);
        slider_col->setObjectName(QStringLiteral("slider_col"));
        slider_col->setGeometry(QRect(210, 68, 171, 21));
        slider_col->setMinimum(9);
        slider_col->setMaximum(19);
        slider_col->setValue(10);
        slider_col->setOrientation(Qt::Horizontal);
        slider_mine = new QSlider(Select_Option);
        slider_mine->setObjectName(QStringLiteral("slider_mine"));
        slider_mine->setGeometry(QRect(210, 110, 171, 21));
        slider_mine->setMinimum(1);
        slider_mine->setValue(8);
        slider_mine->setOrientation(Qt::Horizontal);
        slider_mine->setInvertedControls(false);
        row = new QLineEdit(Select_Option);
        row->setObjectName(QStringLiteral("row"));
        row->setGeometry(QRect(390, 20, 31, 31));
        row->setFont(font1);
        row->setAlignment(Qt::AlignCenter);
        row->setReadOnly(true);
        col = new QLineEdit(Select_Option);
        col->setObjectName(QStringLiteral("col"));
        col->setGeometry(QRect(390, 60, 31, 31));
        col->setFont(font1);
        col->setAlignment(Qt::AlignCenter);
        col->setReadOnly(true);
        mine = new QLineEdit(Select_Option);
        mine->setObjectName(QStringLiteral("mine"));
        mine->setGeometry(QRect(390, 100, 31, 31));
        mine->setFont(font1);
        mine->setAlignment(Qt::AlignCenter);
        mine->setReadOnly(true);

        retranslateUi(Select_Option);

        QMetaObject::connectSlotsByName(Select_Option);
    } // setupUi

    void retranslateUi(QWidget *Select_Option)
    {
        Select_Option->setWindowTitle(QApplication::translate("Select_Option", "Form", Q_NULLPTR));
        pushButton_OK->setText(QApplication::translate("Select_Option", "\320\224\320\260", Q_NULLPTR));
        pushButton_cancel->setText(QApplication::translate("Select_Option", "\320\236\321\202\320\274\320\265\320\275\320\260", Q_NULLPTR));
        lineEdit_row->setText(QApplication::translate("Select_Option", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\201\321\202\321\200\320\276\320\272", Q_NULLPTR));
        lineEdit_row->setPlaceholderText(QString());
        lineEdit_col->setText(QApplication::translate("Select_Option", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\201\321\202\320\276\320\273\320\261\321\206\320\276\320\262", Q_NULLPTR));
        lineEdit_mine->setText(QApplication::translate("Select_Option", "\320\247\320\260\321\201\321\202\320\276\321\202\320\260 \320\274\320\270\320\275", Q_NULLPTR));
        row->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Select_Option: public Ui_Select_Option {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECT_OPTION_H
