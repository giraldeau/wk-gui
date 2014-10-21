#ifndef FILEDOWNLOADER_H
#define FILEDOWNLOADER_H

#include <QObject>
#include <QByteArray>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>

class FileDownloader : public QObject
{
    Q_OBJECT
public:
    explicit FileDownloader(QObject *parent = 0);
    virtual ~FileDownloader();
    QNetworkReply *download(QUrl url);
    QByteArray downloadedData() const;

signals:
    void downloaded();

public slots:

private slots:
    void fileDownloaded(QNetworkReply *pReplay);

private:
    QNetworkAccessManager m_webctl;
    QByteArray m_data;
};

#endif // FILEDOWNLOADER_H
