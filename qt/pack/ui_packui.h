/********************************************************************************
** Form generated from reading UI file 'packui.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PACKUI_H
#define UI_PACKUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_packUI
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QGraphicsView *graphicsView;
    QPushButton *ClearButton;
    QPushButton *PackButton;
    QGroupBox *groupBox;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QGraphicsView *graphicsView_3;
    QGraphicsView *graphicsView_2;
    QGroupBox *groupBox_3;
    QLineEdit *lineEdit_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit_5;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *packUI)
    {
        if (packUI->objectName().isEmpty())
            packUI->setObjectName(QString::fromUtf8("packUI"));
        packUI->setWindowModality(Qt::WindowModal);
        packUI->resize(855, 553);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(packUI->sizePolicy().hasHeightForWidth());
        packUI->setSizePolicy(sizePolicy);
        packUI->setMinimumSize(QSize(855, 553));
        packUI->setMaximumSize(QSize(855, 553));
        packUI->setTabletTracking(false);
        packUI->setAutoFillBackground(false);
        centralwidget = new QWidget(packUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 811, 491));
        gridLayout_3 = new QGridLayout(layoutWidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        groupBox_2->setMinimumSize(QSize(0, 80));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        graphicsView = new QGraphicsView(groupBox_2);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy2);
        graphicsView->setMinimumSize(QSize(130, 70));

        gridLayout_2->addWidget(graphicsView, 0, 0, 1, 1);

        ClearButton = new QPushButton(groupBox_2);
        ClearButton->setObjectName(QString::fromUtf8("ClearButton"));

        gridLayout_2->addWidget(ClearButton, 1, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 0, 1, 1, 1);

        PackButton = new QPushButton(layoutWidget);
        PackButton->setObjectName(QString::fromUtf8("PackButton"));
        PackButton->setMinimumSize(QSize(0, 50));

        gridLayout_3->addWidget(PackButton, 3, 0, 1, 1);

        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy3);
        groupBox->setMinimumSize(QSize(270, 200));
        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 30, 251, 91));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        lineEdit = new QLineEdit(layoutWidget1);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);

        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 3, 2, 1, 1);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 1, 1, 1);

        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(layoutWidget1);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 2, 1, 1);

        lineEdit_3 = new QLineEdit(layoutWidget1);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 3, 0, 1, 1);

        graphicsView_3 = new QGraphicsView(groupBox);
        graphicsView_3->setObjectName(QString::fromUtf8("graphicsView_3"));
        graphicsView_3->setGeometry(QRect(5, 130, 261, 171));

        gridLayout_3->addWidget(groupBox, 1, 0, 2, 1);

        graphicsView_2 = new QGraphicsView(layoutWidget);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(graphicsView_2->sizePolicy().hasHeightForWidth());
        graphicsView_2->setSizePolicy(sizePolicy4);
        graphicsView_2->setMinimumSize(QSize(300, 0));
        graphicsView_2->setTabletTracking(false);

        gridLayout_3->addWidget(graphicsView_2, 1, 1, 3, 1);

        groupBox_3 = new QGroupBox(layoutWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(130);
        sizePolicy5.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy5);
        groupBox_3->setMinimumSize(QSize(70, 130));
        lineEdit_4 = new QLineEdit(groupBox_3);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(12, 67, 61, 22));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(12, 28, 40, 16));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(137, 28, 37, 16));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(137, 67, 16, 16));
        lineEdit_5 = new QLineEdit(groupBox_3);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(149, 67, 61, 22));
        comboBox = new QComboBox(groupBox_3);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(80, 67, 51, 22));
        comboBox_2 = new QComboBox(groupBox_3);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(218, 67, 51, 22));

        gridLayout_3->addWidget(groupBox_3, 0, 0, 1, 1);

        packUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(packUI);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 855, 21));
        packUI->setMenuBar(menubar);
        statusbar = new QStatusBar(packUI);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        packUI->setStatusBar(statusbar);

        retranslateUi(packUI);

        QMetaObject::connectSlotsByName(packUI);
    } // setupUi

    void retranslateUi(QMainWindow *packUI)
    {
        packUI->setWindowTitle(QApplication::translate("packUI", "packUI", nullptr));
        groupBox_2->setTitle(QApplication::translate("packUI", "\320\222\321\213\320\261\321\200\320\260\320\275\320\275\321\213\320\265 \320\270\320\267\320\264\320\265\320\273\320\270\321\217", nullptr));
        ClearButton->setText(QApplication::translate("packUI", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \321\201\320\277\320\270\321\201\320\276\320\272 \320\270\320\267\320\264\320\265\320\273\320\270\320\271", nullptr));
        PackButton->setText(QApplication::translate("packUI", "\320\243\320\277\320\260\320\272\320\276\320\262\320\260\321\202\321\214", nullptr));
        groupBox->setTitle(QApplication::translate("packUI", "\320\230\320\267\320\264\320\265\320\273\320\270\320\265(\320\262 \321\201\320\274)", nullptr));
        label_2->setText(QApplication::translate("packUI", "\320\222\321\213\321\201\320\276\321\202\320\260", nullptr));
        pushButton->setText(QApplication::translate("packUI", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        label_4->setText(QApplication::translate("packUI", "\320\232\320\276\320\273-\320\262\320\276", nullptr));
        label_3->setText(QApplication::translate("packUI", "x", nullptr));
        label->setText(QApplication::translate("packUI", "\320\250\320\270\321\200\320\270\320\275\320\260", nullptr));
        groupBox_3->setTitle(QApplication::translate("packUI", "\320\240\320\260\320\267\320\274\320\265\321\200 \320\273\320\270\321\201\321\202\320\260 \320\274\320\265\321\202\320\260\320\273\320\273\320\260", nullptr));
        lineEdit_4->setInputMask(QString());
        label_5->setText(QApplication::translate("packUI", "\320\250\320\270\321\200\320\270\320\275\320\260", nullptr));
        label_6->setText(QApplication::translate("packUI", "\320\222\321\213\321\201\320\276\321\202\320\260", nullptr));
        label_7->setText(QApplication::translate("packUI", "x", nullptr));
        comboBox->setItemText(0, QApplication::translate("packUI", "\320\241\320\274", nullptr));
        comboBox->setItemText(1, QApplication::translate("packUI", "\320\234", nullptr));

        comboBox_2->setItemText(0, QApplication::translate("packUI", "\320\241\320\274", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("packUI", "\320\234", nullptr));

    } // retranslateUi

};

namespace Ui {
    class packUI: public Ui_packUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PACKUI_H
