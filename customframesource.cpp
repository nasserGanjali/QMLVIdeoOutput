#include "customframesource.h"

CustomFramesource::CustomFramesource(QObject *parent) : QObject(parent)
{
    connect(&timer, SIGNAL(timeout()), SLOT(timerTicked()));
    timer.start(40);
}

void CustomFramesource::timerTicked(){
    QVideoFrame frame(QImage(":/1.jpeg"));
    emit newFrameAvailable(frame);
}
