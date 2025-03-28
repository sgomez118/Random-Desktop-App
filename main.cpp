#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    std::cout << "Hello World" << std::endl;

    return app.exec();
}