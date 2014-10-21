#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->progressBar->reset();

    downloader = new FileDownloader(this);

    connect(ui->pushButton, &QPushButton::clicked,
            this, &MainWindow::doDownload);
    connect(downloader, &FileDownloader::downloaded,
            this, &MainWindow::loadImage);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete downloader;
    delete scene;
}

void MainWindow::doDownload()
{
    QUrl url("http://wk-rpc-server.phd.vm/logo11w.png");
    QNetworkReply *reply = downloader->download(url);
    connect(reply, &QNetworkReply::downloadProgress,
            this, &MainWindow::updateProgress);
}

void MainWindow::updateProgress(qint64 recv, qint64 total)
{
    QProgressBar *p = ui->progressBar;
    p->setMinimum(0);
    p->setMaximum(total);
    p->setValue(recv);
    p->update();
}

void MainWindow::loadImage()
{
    qDebug() << "loadImage()";
    QPixmap pix;
    QByteArray data = downloader->downloadedData();
    pix.loadFromData(data, "PNG");
    scene->clear();
    scene->addPixmap(pix);
    scene->setSceneRect(pix.rect());

}
