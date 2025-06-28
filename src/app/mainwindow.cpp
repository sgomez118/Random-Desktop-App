#include "mainwindow.h"

#include <QStatusBar>
#include <QString>
#include <QTextEdit>
#include <QVBoxLayout>

MainWindow::MainWindow(QMainWindow *parent) : QMainWindow(parent), clickCount(0) {
    // Set MainWindow properties
    setWindowTitle("Random Desktop App");
    setGeometry(0, 0, 800, 400);

    // Create the Dock Manager
    ads::CDockManager* dockManager = new ads::CDockManager(this);

    // Create dockable widgets
    
    // 1. A simple text editor
    ads::CDockWidget* textEditorWidget = new ads::CDockWidget("Text Editor 1");
    textEditorWidget->setWidget(new QTextEdit());
    textEditorWidget->setIcon(style()->standardIcon(QStyle::SP_FileIcon));
    
    // 2. Another text editor
    ads::CDockWidget* notesWidget = new ads::CDockWidget("Notes");
    notesWidget->setWidget(new QTextEdit());
    notesWidget->setIcon(style()->standardIcon(QStyle::SP_FileDialogNewFolder));

    // 3. A label widget for information
    ads::CDockWidget* infoWidget = new ads::CDockWidget("Info");
    infoLabel = new QLabel("This is an information panel.\nYou can drag and drop these widgets.");
    infoLabel->setWordWrap(true);
    infoLabel->setAlignment(Qt::AlignTop);
    infoWidget->setWidget(infoLabel);
    infoWidget->setIcon(style()->standardIcon(QStyle::SP_MessageBoxInformation));
    
    // Add widgets to the dock manager
    dockManager->addDockWidget(ads::RightDockWidgetArea, textEditorWidget);
    dockManager->addDockWidget(ads::BottomDockWidgetArea, notesWidget);
    dockManager->addDockWidget(ads::RightDockWidgetArea, infoWidget, textEditorWidget->dockAreaWidget());
    
    // Create widgets
    ads::CDockWidget* centralWidget = new ads::CDockWidget("Central Document");
    centralWidget->setWidget(new QTextEdit());
    dockManager->addDockWidget(ads::CenterDockWidgetArea, centralWidget);

    createActions();
    createMenus();

    QString message = "A context menu is available by right-clicking";
    statusBar()->showMessage(message);
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