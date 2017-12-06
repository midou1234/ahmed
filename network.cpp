#include "network.h"
#include<QDebug>
#include <QFile>

network::network(QObject *parent) : QObject(parent)
{
 connect(http,SIGNAL(finished(QNetworkReply*)),this, SLOT(readRead(QNetworkReply*)));
}
void network::makeRequest(QString endpointRequest)
{
    http->get(QNetworkRequest(QUrl(endpointRequest)));
    QFile *file =new QFile("E:/ahmed1/test.txt");
    if(file->open(QFile::Append)){
        file->readyRead();
        file->flush();
        file->close();
    }
    else{
    delete file;
    }


}

void network::readRead(QNetworkReply*reply){
QByteArray mydata;
mydata = reply->readAll();
emit(dataReadyRead(mydata));


}
