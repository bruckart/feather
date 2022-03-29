

#include "MyOpenGLWidget.h"

#include <iostream>


MyOpenGLWidget::MyOpenGLWidget()
{

    // Make sure the context is current when deleting the texture
    // and the buffers.
    makeCurrent();

}

MyOpenGLWidget::~MyOpenGLWidget()
{ 
    makeCurrent();

    doneCurrent();
}

void MyOpenGLWidget::initializeGL()
{
    std::clog << "MyOpenGLWidget::initializeGL()" << std::endl;

    // Set up the rendering context, load shaders and other resources, etc.:
    // QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    // f->glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    // ...

    // initializeOpenGLFunctions();
    // glClearColor(...);

    // m_context->makeCurrent(this);
    // initializeOpenGLFunctions();
}

void MyOpenGLWidget::resizeGL(int w, int h)
{
    std::clog << "MyOpenGLWidget::resizeGL()" << std::endl;

    // Update projection matrix and other size related settings:
    // m_projection.setToIdentity();
    // m_projection.perspective(45.0f, w / float(h), 0.01f, 100.0f);
    // ...
}

void MyOpenGLWidget::paintGL()
{
    std::clog << "MyOpenGLWidget::paintGL()" << std::endl;

    // Clear color and depth buffer
    // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Draw the scene:
    // QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    // f->glClear(GL_COLOR_BUFFER_BIT);
    // ...

}





void MyOpenGLWidget::mousePressEvent(QMouseEvent *e)
{
}

void MyOpenGLWidget::mouseReleaseEvent(QMouseEvent *e)
{
}

void MyOpenGLWidget::timerEvent(QTimerEvent *e)
{
}

void MyOpenGLWidget::initShaders()
{
}

void MyOpenGLWidget::initTextures()
{
}

