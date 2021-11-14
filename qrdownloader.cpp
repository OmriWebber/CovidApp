#include "qrdownloader.h"

qrdownloader::qrdownloader(QUrl imageUrl, QObject *parent) :
 QObject(parent)
{
 connect(
  &m_WebCtrl, SIGNAL (finished(QNetworkReply*)),
  this, SLOT (fileDownloaded(QNetworkReply*))
 );

 QNetworkRequest request(imageUrl);
 m_WebCtrl.get(request);
}

qrdownloader::~qrdownloader() { }

void qrdownloader::fileDownloaded(QNetworkReply* pReply) {
 m_DownloadedData = pReply->readAll();
 //emit a signal
 pReply->deleteLater();
 emit downloaded();
}

QByteArray qrdownloader::downloadedData() const {
 return m_DownloadedData;
}
