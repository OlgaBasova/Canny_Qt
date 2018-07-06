#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

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
#include <QHBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:

    QWidget *centralWidget;
    QPushButton *pushButtonOpenImage;    
    QPushButton *pushButtonSaveCannyImage;
    QScrollBar *horizontalScrollBar_Thr1;
    QScrollBar *horizontalScrollBar_Thr2;
    QGraphicsView *graphicsViewImage;
    QGraphicsView *graphicsViewCannyImage;
    QSpinBox *spinBox_Thr1;
    QSpinBox *spinBox_Thr2;
    QSpinBox *spinBox_apertureSize;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;    
    QStatusBar *statusBar;

    QGridLayout *allLayout;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1070, 652);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));

        pushButtonOpenImage = new QPushButton(centralWidget);
        pushButtonOpenImage->setObjectName(QStringLiteral("pushButtonOpenImage"));

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        spinBox_Thr1 = new QSpinBox(centralWidget);
        spinBox_Thr1->setObjectName(QStringLiteral("spinBox_Thr1"));
        horizontalScrollBar_Thr1 = new QScrollBar(centralWidget);
        horizontalScrollBar_Thr1->setOrientation(Qt::Horizontal);

        pushButtonSaveCannyImage = new QPushButton(centralWidget);
        pushButtonSaveCannyImage->setObjectName(QStringLiteral("pushButtonSaveCannyImage"));

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        spinBox_Thr2 = new QSpinBox(centralWidget);
        spinBox_Thr2->setObjectName(QStringLiteral("spinBox_Thr2"));
        horizontalScrollBar_Thr2 = new QScrollBar(centralWidget);
        horizontalScrollBar_Thr2->setObjectName(QStringLiteral("horizontalScrollBar_Thr2"));
        horizontalScrollBar_Thr2->setOrientation(Qt::Horizontal);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        spinBox_apertureSize = new QSpinBox(centralWidget);
        spinBox_apertureSize->setObjectName(QStringLiteral("spinBox_apertureSize"));

        graphicsViewImage = new QGraphicsView(centralWidget);
        graphicsViewImage->setObjectName(QStringLiteral("graphicsViewImage"));
        graphicsViewImage->setEnabled(true);
        graphicsViewImage->setMinimumSize(300,300);
        graphicsViewImage->setSizePolicy(QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum));

        graphicsViewCannyImage = new QGraphicsView(centralWidget);
        graphicsViewCannyImage->setObjectName(QStringLiteral("graphicsViewCannyImage"));
        graphicsViewCannyImage->setMinimumSize(300,300);
        graphicsViewCannyImage->setSizePolicy(QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum));

        allLayout = new QGridLayout;
        allLayout->addWidget(label, 0, 1);
        allLayout->addWidget(spinBox_Thr1, 0, 2);
        allLayout->addWidget(horizontalScrollBar_Thr1, 0, 3);

        allLayout->addWidget(pushButtonOpenImage, 1, 0);
        allLayout->addWidget(label_2, 1, 1);
        allLayout->addWidget(spinBox_Thr2, 1, 2);
        allLayout->addWidget(horizontalScrollBar_Thr2, 1, 3);

        allLayout->addWidget(pushButtonSaveCannyImage, 2, 0);
        allLayout->addWidget(label_3, 2, 1);
        allLayout->addWidget(spinBox_apertureSize, 2, 2);

        allLayout->addWidget(graphicsViewImage, 3, 0, 2, 2);
        allLayout->addWidget(graphicsViewCannyImage, 3, 2, 2, 2);

        centralWidget->setLayout(allLayout);


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
