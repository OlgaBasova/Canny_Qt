#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <opencv2/imgcodecs.hpp>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label->setText("First threshold");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label_2->setText("Second threshold");
    ui->label_2->setAlignment(Qt::AlignRight);
    ui->label_3->setText("Aperture size");
    ui->label_3->setAlignment(Qt::AlignRight);

    ui->spinBox_apertureSize->setMaximum(5);
    ui->spinBox_apertureSize->setMinimum(3);
    ui->spinBox_apertureSize->setSingleStep(2);

    ui->horizontalScrollBar_Thr1->setMaximum(100);
    ui->spinBox_Thr1->setMaximum(100);
    ui->horizontalScrollBar_Thr2->setMaximum(ui->horizontalScrollBar_Thr1->maximum()*3);
    ui->spinBox_Thr2->setMaximum(ui->spinBox_Thr1->maximum()*3);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ShowImage(QImage &imageObject, int numbOfViewImage)
{
    QPixmap image = QPixmap::fromImage(imageObject);

    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->addPixmap(image);
    scene->setSceneRect(image.rect());
    switch (numbOfViewImage)
    {
    case 0:
        ui->graphicsViewImage->setScene(scene);
        ui->graphicsViewImage->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
        break;
    case 1:
        ui->graphicsViewCannyImage->setScene(scene);
        ui->graphicsViewCannyImage->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
        break;
    }
}

QImage Mat2QImage(cv::Mat const& src)
{
    static QVector<QRgb>  colorTable(256);
    for(int i = 0; i < 256; i++)
    {
        colorTable[i] = qRgb(i, i, i);
    }
    QImage result(src.data, src.cols, src.rows, static_cast<int>(src.step), QImage::Format_Indexed8);
    result.setColorTable( colorTable );
    return result;
}

void MainWindow::NewCanny()
{
    int threshold1 = ui->spinBox_Thr1->value();
    int threshold2 = ui->spinBox_Thr2->value();
    int apertureSize = ui->spinBox_apertureSize->value();
    Canny(grayImageMat, imageMatCanny, threshold1, threshold2, apertureSize, false);

    imageObjectCanny = Mat2QImage(imageMatCanny);
    ShowImage(imageObjectCanny, 1);
}

void MainWindow::on_pushButtonOpenImage_clicked()
{
    QString imagePath = QFileDialog::getOpenFileName(this, "Open Image", "");
    String const s = imagePath.toStdString();
    imageMat = cv::imread(s, 1);
    grayImageMat = imread(imagePath.toStdString(), 0);
    imageObject.load(imagePath);
    ShowImage(imageObject, 0);
}

void MainWindow::on_spinBox_Thr1_valueChanged(int arg1)
{
    NewCanny();
}

void MainWindow::on_spinBox_Thr2_valueChanged(int arg1)
{
    NewCanny();
}

void MainWindow::on_spinBox_apertureSize_valueChanged(int arg1)
{
    NewCanny();
}

void MainWindow::on_pushButtonSaveCannyImage_clicked()
{
    QString imagePath = QFileDialog::getSaveFileName(this, "Save Image");
    imwrite(imagePath.toStdString(), imageMatCanny);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    ShowImage(imageObject, 0);
    if (!imageObjectCanny.isNull())
        ShowImage(imageObjectCanny, 1);
}
