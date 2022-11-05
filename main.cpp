#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "FrameProvider.h"
#include "customframesource.h"

 int main(int argc, char *argv[])
{
    // initialize the qml application engine
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    //register the custom control to the qml application engine
    qmlRegisterType<FameProvider>("com.yourcompany.FrameProvider", 1, 0, "FrameProvider");

    // start the view
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
    {
    return -1;
    }

    // find your custom control
    QObject *rootObject = engine.rootObjects().first();
    QObject *display = rootObject->findChild<QObject *>("display");
    auto provider = qvariant_cast<FameProvider *>(display->property("source"));

    // Create your custom frame source class, which inherits from QObject. This source is expected to have the following public fields and signals:
    // - int width
    // - int height
    // - int format (following QVideoFrame::PixelFormat)
    // - signals: void newFrameAvailable(const QVideoFrame &frame);
    CustomFramesource source;

    // Set the correct format for the video surface (Make sure your selected format is supported by the surface)
    provider->setFormat(source.width,source.height, source.format);

    // Connect your frame source with the provider
    QObject::connect(&source, SIGNAL(newFrameAvailable(const QVideoFrame &)), provider, SLOT(onNewVideoContentReceived(const QVideoFrame &)));

    // run the app
    int retVal =  app.exec();

    return 0;
}
