#include "filedownloader.h"

FileDownloader::FileDownloader(QObject *parent) :
    QObject(parent)
{
    connect(&m_webctl, &QNetworkAccessManager::finished,
            this, &FileDownloader::fileDownloaded);
}

FileDownloader::~FileDownloader()
{
}

QNetworkReply *FileDownloader::download(QUrl url)
{
    QNetworkRequest request(url);
    QNetworkReply *dw = m_webctl.get(request);
    return dw;
}

void FileDownloader::fileDownloaded(QNetworkReply *pReply)
{
    m_data = pReply->readAll();
    pReply->deleteLater();
    emit downloaded();
}

QByteArray FileDownloader::downloadedData() const
{
    return m_data;
}
