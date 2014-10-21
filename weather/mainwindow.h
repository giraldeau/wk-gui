#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QDebug>
#include "filedownloader.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void doDownload();
    void loadImage();
    void updateProgress(qint64, qint64);

private:
    Ui::MainWindow *ui;
    FileDownloader *downloader;
    QGraphicsScene *scene;

};

#endif // MAINWINDOW_H
