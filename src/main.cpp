#include <QApplication>

#include "MyOpenGLWidget.h"

#include <iostream>


int main(int argc, char* argv[])
{
	std::clog << "Hello, World." << std::endl;
	
    QApplication app(argc, argv);
    app.setOrganizationName("");
    app.setApplicationName("feather");
    app.setApplicationVersion("1.0.0");

    MyOpenGLWidget w;
    w.show();

    return app.exec();
}
