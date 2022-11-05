#ifndef CUSTOMFRAMESOURCE_H
#define CUSTOMFRAMESOURCE_H

#include <QObject>
#include <QVideoFrame>
#include <QTimer>
#include <QImage>

class CustomFramesource : public QObject
{
    Q_OBJECT
public:
    explicit CustomFramesource(QObject *parent = nullptr);
    int width = 800;
    int height = 600;
    QVideoFrame::PixelFormat format = QVideoFrame::Format_RGB32; //(following QVideoFrame::PixelFormat)

    QTimer timer;
private slots:
    void timerTicked();
signals:
    void newFrameAvailable(const QVideoFrame &frame);

};

#endif // CUSTOMFRAMESOURCE_H
