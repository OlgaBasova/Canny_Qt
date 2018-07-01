#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label->setText("First threshold for the hysteresis procedure");
    ui->label_2->setText("Second threshold for the hysteresis procedure");
    ui->label_3->setText("Aperture size for the Sobel operator");

    ui->spinBox_apertureSize->setMaximum(7);
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

    int ConstViewImageWidth = ui->graphicsViewImage->width();
    if (image.height() > ConstViewImageWidth)
    {
        image = image.scaled(ConstViewImageWidth, image.height()*ConstViewImageWidth/image.width());
    }

    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->addPixmap(image);
    scene->setSceneRect(image.rect());
    switch (numbOfViewImage)
    {
    case 0:
        ui->graphicsViewImage->setScene(scene);
        break;
    case 1:
        ui->graphicsViewCannyImage->setScene(scene);
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
    Canny(imageMat, imageMatCanny, threshold1, threshold2, apertureSize, false);

    QImage  imageObjectCanny = Mat2QImage(imageMatCanny);
    ShowImage(imageObjectCanny, 1);
}

void MainWindow::on_pushButtonOpenImage_clicked()
{
    QString imagePath = QFileDialog::getOpenFileName(this, "Open Image", "");
    imageMat = imread(imagePath.toStdString(), 3);
    QImage  imageObject;
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
