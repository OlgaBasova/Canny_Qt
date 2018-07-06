/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

//#include <QtCore/QVariant>
//#include <QtWidgets/QAction>
//#include <QtWidgets/QApplication>
//#include <QtWidgets/QButtonGroup>
//#include <QtWidgets/QGraphicsView>
//#include <QtWidgets/QHeaderView>
//#include <QtWidgets/QLabel>
//#include <QtWidgets/QMainWindow>
//#include <QtWidgets/QPushButton>
//#include <QtWidgets/QScrollBar>
//#include <QtWidgets/QSpinBox>
//#include <QtWidgets/QStatusBar>
//#include <QtWidgets/QWidget>

#include <QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QGraphicsView>
#include <QHeaderView>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QScrollBar>
#include <QSpinBox>
#include <QStatusBar>
#include <QWidget>
#include <qstring.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:

    QWidget *centralWidget;
    QPushButton *pushButtonOpenImage;
    QLabel *label;
    QScrollBar *horizontalScrollBar_Thr1;
    QGraphicsView *graphicsViewImage;
    QSpinBox *spinBox_Thr1;
    QSpinBox *spinBox_Thr2;
    QSpinBox *spinBox_apertureSize;
    QScrollBar *horizontalScrollBar_Thr2;
    QPushButton *pushButtonSaveCannyImage;
    QLabel *label_2;
    QLabel *label_3;
    QGraphicsView *graphicsViewCannyImage;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1070, 652);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButtonOpenImage = new QPushButton(centralWidget);
        pushButtonOpenImage->setObjectName(QStringLiteral("pushButtonOpenImage"));
        pushButtonOpenImage->setGeometry(QRect(10, 20, 131, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(220, 10, 221, 20));
        horizontalScrollBar_Thr1 = new QScrollBar(centralWidget);
        horizontalScrollBar_Thr1->setObjectName(QStringLiteral("horizontalScrollBar_Thr1"));
        horizontalScrollBar_Thr1->setGeometry(QRect(514, 10, 321, 16));
        horizontalScrollBar_Thr1->setOrientation(Qt::Horizontal);
        graphicsViewImage = new QGraphicsView(centralWidget);
        graphicsViewImage->setObjectName(QStringLiteral("graphicsViewImage"));
        graphicsViewImage->setEnabled(true);
        graphicsViewImage->setGeometry(QRect(10, 100, 521, 521));
        spinBox_Thr1 = new QSpinBox(centralWidget);
        spinBox_Thr1->setObjectName(QStringLiteral("spinBox_Thr1"));
        spinBox_Thr1->setGeometry(QRect(454, 10, 51, 22));
        spinBox_Thr2 = new QSpinBox(centralWidget);
        spinBox_Thr2->setObjectName(QStringLiteral("spinBox_Thr2"));
        spinBox_Thr2->setGeometry(QRect(454, 40, 51, 22));
        spinBox_apertureSize = new QSpinBox(centralWidget);
        spinBox_apertureSize->setObjectName(QStringLiteral("spinBox_apertureSize"));
        spinBox_apertureSize->setGeometry(QRect(454, 70, 51, 22));
        horizontalScrollBar_Thr2 = new QScrollBar(centralWidget);
        horizontalScrollBar_Thr2->setObjectName(QStringLiteral("horizontalScrollBar_Thr2"));
        horizontalScrollBar_Thr2->setGeometry(QRect(514, 40, 321, 16));
        horizontalScrollBar_Thr2->setOrientation(Qt::Horizontal);
        pushButtonSaveCannyImage = new QPushButton(centralWidget);
        pushButtonSaveCannyImage->setObjectName(QStringLiteral("pushButtonSaveCannyImage"));
        pushButtonSaveCannyImage->setGeometry(QRect(10, 60, 131, 23));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(220, 40, 231, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(220, 70, 221, 20));
        graphicsViewCannyImage = new QGraphicsView(centralWidget);
        graphicsViewCannyImage->setObjectName(QStringLiteral("graphicsViewCannyImage"));
        graphicsViewCannyImage->setGeometry(QRect(540, 100, 521, 521));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(horizontalScrollBar_Thr1, SIGNAL(valueChanged(int)), spinBox_Thr1, SLOT(setValue(int)));
        QObject::connect(spinBox_Thr1, SIGNAL(valueChanged(int)), horizontalScrollBar_Thr1, SLOT(setValue(int)));
        QObject::connect(horizontalScrollBar_Thr2, SIGNAL(valueChanged(int)), spinBox_Thr2, SLOT(setValue(int)));
        QObject::connect(spinBox_Thr2, SIGNAL(valueChanged(int)), horizontalScrollBar_Thr2, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButtonOpenImage->setText(QApplication::translate("MainWindow", "Open Image", 0));
        label->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        pushButtonSaveCannyImage->setText(QApplication::translate("MainWindow", "Save Canny Image", 0));
        label_2->setText(QApplication::translate("MainWindow", "Second threshold for the hysteresis procedure", 0));
        label_3->setText(QApplication::translate("MainWindow", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
