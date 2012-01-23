#ifndef _YouTubeSearch_h
#define _YouTubeSearch_h

#include <QObject>
#include <QtNetwork>
#include <QDesktopServices>
#include <QtXmlPatterns>
#include <QDeclarativeContext>

#include "Media.h"

#define CACHE_SIZE 128 * 1024 * 1024
#define YOUTUBE_API "https://gdata.youtube.com/feeds/api/videos?max-results=30&"
#define YTIMG "http://i%1.ytimg.com/vi/%2/hqdefault.jpg"



class YouTubeSearch : public QObject
{
    public:
        explicit YouTubeSearch(QObject *parent = 0);

        ~YouTubeSearch();

        void setContext(QDeclarativeContext *context);

    public slots:
        void search(const QString& query);

    protected slots:
        void error(QNetworkReply::NetworkError code);

        void finished();

    private:
        Q_OBJECT
        Q_DISABLE_COPY(YouTubeSearch)

        QNetworkAccessManager manager;
        QNetworkDiskCache cache;
        QNetworkReply *m_reply;
        QDeclarativeContext *m_context;
        QList<QObject *> m_objects;
};

#endif
