#include "camerawidget.h"

#include <QMediaDevices>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QPalette>

CameraWidget::CameraWidget(QWidget *parent)
    : QWidget(parent), camera(new QCamera(this)), captureSession(new QMediaCaptureSession(this)), videoWidget(new QVideoWidget(this)) {
    // Set up the video widget
    videoWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    videoWidget->setAutoFillBackground(true);
    QPalette palette = videoWidget->palette();
    palette.setColor(QPalette::Window, Qt::black);
    videoWidget->setPalette(palette);
    
    // Controls panel
    cameraSelectionBox = new QComboBox(this);
    startButton = new QPushButton("Start Camera", this);
    stopButton = new QPushButton("Stop Camera", this);
    stopButton->setEnabled(false);

    // Layout for the controls
    QWidget *controlsContainer = new QWidget();
    QHBoxLayout *controlsLayout = new QHBoxLayout(controlsContainer);
    controlsLayout->addWidget(cameraSelectionBox);
    controlsLayout->addWidget(startButton);
    controlsLayout->addWidget(stopButton);
    
    // Set up the layout for video and controls
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(videoWidget);
    layout->addWidget(controlsContainer);
    setLayout(layout);

    // Configure the capture session
    captureSession->setCamera(camera);
    captureSession->setVideoOutput(videoWidget);

    // Populate camera selector and start the camera
    populateCameraSelector();

    // Connect signals and slots
    connect(startButton, &QPushButton::clicked, this, &CameraWidget::startCamera);
    connect(stopButton, &QPushButton::clicked, this, &CameraWidget::stopCamera);
    connect(camera, &QCamera::errorOccurred, this, &CameraWidget::handleCameraError);
}

void CameraWidget::startCamera() {
    int selectedIndex = cameraSelectionBox->currentIndex();
    if (selectedIndex < 0) {
        QMessageBox::warning(this, "Error", "No camera selected.");
        return; // No camera selected
    }

    QCameraDevice selectedDevice = cameraSelectionBox->itemData(selectedIndex).value<QCameraDevice>();
    camera->setCameraDevice(selectedDevice);

    camera->start();
    
    startButton->setEnabled(false);
    stopButton->setEnabled(true);
    cameraSelectionBox->setEnabled(false);
}

void CameraWidget::stopCamera() {
    camera->stop();

    startButton->setEnabled(true);
    stopButton->setEnabled(false);
    cameraSelectionBox->setEnabled(true);
}

void CameraWidget::handleCameraError() {
    QMessageBox::critical(this, "Camera Error", camera->errorString());
    stopCamera();
}

void CameraWidget::populateCameraSelector() {
    const QList<QCameraDevice> availableCameras = QMediaDevices::videoInputs();
    if (availableCameras.isEmpty()) {
        QMessageBox::warning(this, "No Cameras", "No web cameras were found on this system.");
        startButton->setEnabled(false);
        return; // No cameras available
    }

    for (const QCameraDevice &cameraDevice : availableCameras) {
        cameraSelectionBox->addItem(cameraDevice.description(), QVariant::fromValue(cameraDevice));
    }
}