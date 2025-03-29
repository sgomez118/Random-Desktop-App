#pragma once

#include <QWidget>

class QLabel;
class QPushButton;
class QVBoxLayout;

class MainWindow : public QWidget {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();

private slots:
    void onButtonClick();

private:
    QLabel *greetingLabel;
    QPushButton *clickButton;
    QVBoxLayout *mainLayout;

    int clickCount;
};