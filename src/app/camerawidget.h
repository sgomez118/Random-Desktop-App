#ifndef CAMERAWIDGET_H
#define CAMERAWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QComboBox>
#include <QCamera>
#include <QVideoWidget>
#include <QMediaCaptureSession>


class CameraWidget : public QWidget {
    Q_OBJECT
public:
    explicit CameraWidget(QWidget *parent = nullptr);

private slots:
    void startCamera();
    void stopCamera();
    void handleCameraError();

private:
    void populateCameraSelector();

    QCamera *camera;
    QMediaCaptureSession *captureSession;
    QVideoWidget *videoWidget;

    QComboBox *cameraSelectionBox;
    QPushButton *startButton;
    QPushButton *stopButton;
};
#endif // CAMERAWIDGET_H