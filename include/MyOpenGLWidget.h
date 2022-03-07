#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#include <QOpenGLWidget>
#include <QScreen>
#include <QWindow>


class MyOpenGLWidget : public QOpenGLWidget
{
public:
    MyOpenGLWidget();
    ~MyOpenGLWidget();

protected:

    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
    void timerEvent(QTimerEvent *e) override;

    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    void initShaders();
    void initTextures();

private:

    

};

#endif // MYOPENGLWIDGET_H
