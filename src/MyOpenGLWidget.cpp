

#include "MyOpenGLWidget.h"


MyOpenGLWidget::MyOpenGLWidget()
{

    // Make sure the context is current when deleting the texture
    // and the buffers.
    makeCurrent();



}

MyOpenGLWidget::~MyOpenGLWidget()
{ 
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

void MyOpenGLWidget::initializeGL()
{
    m_context->makeCurrent(this);
    initializeOpenGLFunctions();
}

void MyOpenGLWidget::resizeGL(int w, int h)
{

}

void MyOpenGLWidget::paintGL()
{
    // Clear color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);









}



void MyOpenGLWidget::initShaders()
{

}

void MyOpenGLWidget::initTextures()
{

}

