#ifndef QRDOWNLOADER_H
#define QRDOWNLOADER_H

#include <QObject>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class qrdownloader : public QObject
{
 Q_OBJECT
 public:
  explicit qrdownloader(QUrl imageUrl, QObject *parent = 0);
  virtual ~qrdownloader();
  QByteArray downloadedData() const;

 signals:
  void downloaded();

 private slots:
  void fileDownloaded(QNetworkReply* pReply);
  private:
  QNetworkAccessManager m_WebCtrl;
  QByteArray m_DownloadedData;
};


#endif // QRDOWNLOADER_H
