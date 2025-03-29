#include "mainwindow.h"

#include <QAction>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QVBoxLayout>
#include <QMenuBar>

MainWindow::MainWindow(QMainWindow *parent) : QMainWindow(parent), clickCount(0) {
    // Set MainWindow properties
    setWindowTitle("Random Desktop App");
    setGeometry(0, 0, 800, 400);

    // Create widgets
    QWidget *widget = new QWidget;
    setCentralWidget(widget);
    
    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    infoLabel = new QLabel(tr("<i>Choose a menu option, or right-click to invoke a context menu</i>"));
    infoLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    infoLabel->setAlignment(Qt::AlignCenter);

    greetingLabel = new QLabel("Hello, World!", this);
    clickButton = new QPushButton("Click Me!", this);

    QWidget *bottomFiller = new QWidget;
    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Set Layout
    auto layout = new QVBoxLayout;
    layout->setContentsMargins(5, 5, 5, 5);
    layout->addWidget(topFiller);
    layout->addWidget(infoLabel);
    layout->addWidget(greetingLabel);
    layout->addWidget(clickButton);
    layout->addWidget(bottomFiller);
    widget->setLayout(layout);

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