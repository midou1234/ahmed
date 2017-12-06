#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>
#include <QDebug>

class network : public QObject
{
    Q_OBJECT
public:
    explicit network(QObject *parent = nullptr);
void makeRequest(QString endpointRequest);
signals:
void dataReadyRead(QByteArray);

public slots:
void readRead(QNetworkReply*reply);
private :
QNetworkAccessManager *http= new QNetworkAccessManager(this);

};


#endif // NETWORK_H
