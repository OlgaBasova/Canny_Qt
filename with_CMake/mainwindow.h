#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QFileDialog>
#include <QResizeEvent>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void resizeEvent(QResizeEvent *event);

private slots:
    void NewCanny();
    void ShowImage(QImage &imageObject, int numbOfViewImage);

    void on_pushButtonOpenImage_clicked();
    void on_spinBox_Thr1_valueChanged(int arg1);
    void on_spinBox_Thr2_valueChanged(int arg1);
    void on_spinBox_apertureSize_valueChanged(int arg1);
    void on_pushButtonSaveCannyImage_clicked();


private:
    Ui::MainWindow *ui;
    QImage  imageObject;
    Mat imageMat;
    Mat grayImageMat;
    QImage  imageObjectCanny;
    Mat imageMatCanny;
};

#endif // MAINWINDOW_H
