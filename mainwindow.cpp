#include "mainwindow.h"

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QString>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent), clickCount(0) {
    setWindowTitle("Random Desktop App");

    greetingLabel = new QLabel("Hello, World!", this);
    clickButton = new QPushButton("Click Me!", this);

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(greetingLabel);
    mainLayout->addWidget(clickButton);

    this->setLayout(mainLayout);

    connect(clickButton, &QPushButton::clicked, this, &MainWindow::onButtonClick);
}

MainWindow::~MainWindow() {
    qDebug("MainWindow destroyed");
}

void MainWindow::onButtonClick() {
    qDebug("Button clicked!");

    clickCount++;
    QString newText = QString("Button clicked %1 times!").arg(clickCount);
    greetingLabel->setText(newText);
}