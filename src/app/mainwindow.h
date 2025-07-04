#ifndef RDA_APP_MAINWINDOW_H_
#define RDA_APP_MAINWINDOW_H_

#include <QWidget>
#include <QMainWindow>
#include <QAction>
#include <QActionGroup>
#include <QLabel>
#include <QMenuBar>
#include <QPushButton>

#include "DockManager.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QMainWindow *parent = nullptr);
    virtual ~MainWindow();

protected:
#ifndef QT_NO_CONTEXT_MENU
    // void contextMenuEvent(QContextMenuEvent *event) override;
#endif // QT_NO_CONTEXT_MENU

private slots:
    void onButtonClick();

    void newFile();
    void open();
    void save();
    void print();
    // void undo();
    // void redo();
    // void cut();
    // void copy();
    // void paste();
    // void bold();
    // void italic();
    // void leftAlign();
    // void rightAlign();
    // void justify();
    // void center();
    // void setLineSpacing();
    // void setParagraphSpacing();
    // void about();
    // void aboutQt();

private:
    void createActions();
    void createMenus();

    QLabel *greetingLabel;
    QPushButton *clickButton;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *formatMenu;
    QMenu *helpMenu;
    QActionGroup *alignmentGroup;
    QAction *newAct;
    QAction *openAct;
    QAction *saveAct;
    QAction *printAct;
    QAction *exitAct;
    QAction *undoAct;
    QAction *redoAct;
    QAction *cutAct;
    QAction *copyAct;
    QAction *pasteAct;
    QAction *boldAct;
    QAction *italicAct;
    QAction *leftAlignAct;
    QAction *rightAlignAct;
    QAction *justifyAct;
    QAction *centerAct;
    QAction *setLineSpacingAct;
    QAction *setParagraphSpacingAct;
    QAction *aboutAct;
    QAction *aboutQtAct;
    QLabel *infoLabel;

    int clickCount;
};

#endif // RDA_APP_MAINWINDOW_H_