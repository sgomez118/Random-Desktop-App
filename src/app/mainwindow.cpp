#include "mainwindow.h"

#include <QStatusBar>
#include <QString>
#include <QVBoxLayout>

MainWindow::MainWindow(QMainWindow *parent) : QMainWindow(parent), clickCount(0) {
    // Set MainWindow properties
    setWindowTitle("Random Desktop App");
    setGeometry(0, 0, 800, 400);

    
    // Create widgets
    QWidget *widget = new QWidget;
    setCentralWidget(widget);
    
    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    infoLabel = new QLabel("<i>Choose a menu option, or right-click to invoke a context menu</i>");
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

    createActions();
    createMenus();

    QString message = "A context menu is available by right-clicking";
    statusBar()->showMessage(message);

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

void MainWindow::createActions() {
    // file menu actions
    newAct = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::DocumentNew), "&New", this);
    newAct->setShortcut(QKeySequence::New);
    newAct->setStatusTip("Create a new file");
    connect(newAct, &QAction::triggered, this, &MainWindow::newFile);

    openAct = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen),"&Open", this);
    openAct->setShortcut(QKeySequence::Open);
    openAct->setStatusTip("Open a file");
    connect(openAct, &QAction::triggered, this, &MainWindow::open);

    saveAct = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave), "&Save", this);
    saveAct->setShortcut(QKeySequence::Save);
    saveAct->setStatusTip("Save file");
    connect(saveAct, &QAction::triggered, this, &MainWindow::save);

    printAct = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::DocumentPrint), "&Print", this);
    printAct->setShortcut(QKeySequence::Print);
    printAct->setStatusTip("Print file");
    connect(printAct, &QAction::triggered, this, &MainWindow::print);

    exitAct = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit), "&Exit", this);
    exitAct->setStatusTip("Exit application");
    // connect

    // edit menu actions
    undoAct = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::EditUndo), "&Undo", this);
    undoAct->setShortcut(QKeySequence::Undo);
    
    // Help Menu
}

void MainWindow::createMenus() {
    fileMenu = menuBar()->addMenu("&File");
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(printAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    editMenu = menuBar()->addMenu("&Edit");
    
    helpMenu = menuBar()->addMenu("&Help");
}

void MainWindow::newFile() {
    qInfo("Create a new file!");

    greetingLabel->setText("Create a new file!");
}

void MainWindow::open() {
    qInfo("Open a file!");

    greetingLabel->setText("Open a file!");
}

void MainWindow::save() {
    qInfo("Save a file!");

    greetingLabel->setText("Save a file!");
}

void MainWindow::print() {
    qInfo("Print file!");

    greetingLabel->setText("Print file!");
}