// #include <QApplication>
#include <QGuiApplication>

#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>
#include <Qt3DCore/QAspectEngine>

#include <Qt3DRender/QCamera>
#include <Qt3DRender/QCameraLens>
#include <Qt3DRender/QAttribute>
#include <Qt3DRender/QBuffer>

#include <Qt3DExtras/QOrbitCameraController>

#include <Qt3DInput/QInputAspect>

#include <Qt3DRender/QRenderAspect>
#include <Qt3DExtras/QForwardRenderer>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DExtras/QCylinderMesh>
#include <Qt3DExtras/QSphereMesh>
#include <Qt3DExtras/QTorusMesh>
#include <Qt3DExtras/QPlaneMesh>
#include <Qt3DExtras/QText2DEntity>

#include <Qt3DExtras/Qt3DWindow>


#include <QPropertyAnimation>

// #include "qorbitcameracontroller.h"
#include "MyOrbitTransformController.h"

// #include "MyGraphicsScene.h"
#include "MyOpenGLWidget.h"

#include <iostream>


void drawLine(const QVector3D& start, const QVector3D& end, 
              const QColor& color,
              Qt3DCore::QEntity *_rootEntity)
{
	auto *geometry = new Qt3DRender::QGeometry(_rootEntity);

	// position vertices (start and end)
	QByteArray bufferBytes;
	bufferBytes.resize(3 * 2 * sizeof(float)); // start.x, start.y, start.end + end.x, end.y, end.z
	float *positions = reinterpret_cast<float*>(bufferBytes.data());
	*positions++ = start.x();
	*positions++ = start.y();
	*positions++ = start.z();
	*positions++ = end.x();
	*positions++ = end.y();
	*positions++ = end.z();

	auto *buf = new Qt3DRender::QBuffer(geometry);
	buf->setData(bufferBytes);

	auto *positionAttribute = new Qt3DRender::QAttribute(geometry);
	positionAttribute->setName(Qt3DRender::QAttribute::defaultPositionAttributeName());
	positionAttribute->setVertexBaseType(Qt3DRender::QAttribute::Float);
	positionAttribute->setVertexSize(3);
	positionAttribute->setAttributeType(Qt3DRender::QAttribute::VertexAttribute);
	positionAttribute->setBuffer(buf);
	positionAttribute->setByteStride(3 * sizeof(float));
	positionAttribute->setCount(2);
	geometry->addAttribute(positionAttribute); // We add the vertices in the geometry

	// connectivity between vertices
	QByteArray indexBytes;
	indexBytes.resize(2 * sizeof(unsigned int)); // start to end
	unsigned int *indices = reinterpret_cast<unsigned int*>(indexBytes.data());
	*indices++ = 0;
	*indices++ = 1;

	auto *indexBuffer = new Qt3DRender::QBuffer(geometry);
	indexBuffer->setData(indexBytes);

	auto *indexAttribute = new Qt3DRender::QAttribute(geometry);
	indexAttribute->setVertexBaseType(Qt3DRender::QAttribute::UnsignedInt);
	indexAttribute->setAttributeType(Qt3DRender::QAttribute::IndexAttribute);
	indexAttribute->setBuffer(indexBuffer);
	indexAttribute->setCount(2);
	geometry->addAttribute(indexAttribute); // We add the indices linking the points in the geometry

	// mesh
	auto *line = new Qt3DRender::QGeometryRenderer(_rootEntity);
	line->setGeometry(geometry);
	line->setPrimitiveType(Qt3DRender::QGeometryRenderer::Lines);

	auto *material = new Qt3DExtras::QPhongMaterial(_rootEntity);
	material->setAmbient(color);

	// entity
	auto *lineEntity = new Qt3DCore::QEntity(_rootEntity);
	lineEntity->addComponent(line);
	lineEntity->addComponent(material);
}

Qt3DCore::QEntity *createScene()
{
    // Root entity
    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity;

    // Material
    Qt3DRender::QMaterial *material = new Qt3DExtras::QPhongMaterial(rootEntity);


    drawLine({ 0, 0, 0 }, { 1, 0, 0 }, Qt::red, rootEntity); // X
    drawLine({ 0, 0, 0 }, { 0, 1, 0 }, Qt::green, rootEntity); // Y
    drawLine({ 0, 0, 0 }, { 0, 0, 1 }, Qt::blue, rootEntity); // Z


    drawLine({-10, 0, -10}, {-10, 0, 10}, Qt::lightGray, rootEntity);
    drawLine({-9, 0, -10}, {-9, 0, 10}, Qt::lightGray, rootEntity);
    drawLine({-8, 0, -10}, {-8, 0, 10}, Qt::lightGray, rootEntity);
    drawLine({-7, 0, -10}, {-7, 0, 10}, Qt::lightGray, rootEntity);
    drawLine({-6, 0, -10}, {-6, 0, 10}, Qt::lightGray, rootEntity);
    drawLine({-5, 0, -10}, {-5, 0, 10}, Qt::lightGray, rootEntity);
    drawLine({-4, 0, -10}, {-4, 0, 10}, Qt::lightGray, rootEntity);
    drawLine({-3, 0, -10}, {-3, 0, 10}, Qt::lightGray, rootEntity);
    drawLine({-2, 0, -10}, {-2, 0, 10}, Qt::lightGray, rootEntity);
    drawLine({-1, 0, -10}, {-1, 0, 10}, Qt::lightGray, rootEntity);
    drawLine({0, 0, -10}, {0, 0, 10}, Qt::lightGray, rootEntity);
    drawLine({1, 0, -10}, {1, 0, 10}, Qt::lightGray, rootEntity);
    drawLine({2, 0, -10}, {2, 0, 10}, Qt::lightGray, rootEntity);
    drawLine({3, 0, -10}, {3, 0, 10}, Qt::lightGray, rootEntity);
    drawLine({4, 0, -10}, {4, 0, 10}, Qt::lightGray, rootEntity);
    drawLine({5, 0, -10}, {5, 0, 10}, Qt::lightGray, rootEntity);
    drawLine({6, 0, -10}, {6, 0, 10}, Qt::lightGray, rootEntity);
    drawLine({7, 0, -10}, {7, 0, 10}, Qt::lightGray, rootEntity);
    drawLine({8, 0, -10}, {8, 0, 10}, Qt::lightGray, rootEntity);
    drawLine({9, 0, -10}, {9, 0, 10}, Qt::lightGray, rootEntity);
    drawLine({10, 0, -10}, {10, 0, 10}, Qt::lightGray, rootEntity);

    drawLine({-10, 0, -10}, {10, 0, -10}, Qt::lightGray, rootEntity);
    drawLine({-10, 0,  -9}, {10, 0, -9}, Qt::lightGray, rootEntity);
    drawLine({-10, 0,  -8}, {10, 0, -8}, Qt::lightGray, rootEntity);
    drawLine({-10, 0,  -7}, {10, 0, -7}, Qt::lightGray, rootEntity);
    drawLine({-10, 0,  -6}, {10, 0, -6}, Qt::lightGray, rootEntity);
    drawLine({-10, 0,  -5}, {10, 0, -5}, Qt::lightGray, rootEntity);
    drawLine({-10, 0,  -4}, {10, 0, -4}, Qt::lightGray, rootEntity);
    drawLine({-10, 0,  -3}, {10, 0, -3}, Qt::lightGray, rootEntity);
    drawLine({-10, 0,  -2}, {10, 0, -2}, Qt::lightGray, rootEntity);
    drawLine({-10, 0,  -1}, {10, 0, -1}, Qt::lightGray, rootEntity);
    drawLine({-10, 0,   0}, {10, 0,  0}, Qt::lightGray, rootEntity);
    drawLine({-10, 0,   1}, {10, 0,  1}, Qt::lightGray, rootEntity);
    drawLine({-10, 0,   2}, {10, 0,  2}, Qt::lightGray, rootEntity);
    drawLine({-10, 0,   3}, {10, 0,  3}, Qt::lightGray, rootEntity);
    drawLine({-10, 0,   4}, {10, 0,  4}, Qt::lightGray, rootEntity);
    drawLine({-10, 0,   5}, {10, 0,  5}, Qt::lightGray, rootEntity);
    drawLine({-10, 0,   6}, {10, 0,  6}, Qt::lightGray, rootEntity);
    drawLine({-10, 0,   7}, {10, 0,  7}, Qt::lightGray, rootEntity);
    drawLine({-10, 0,   8}, {10, 0,  8}, Qt::lightGray, rootEntity);
    drawLine({-10, 0,   9}, {10, 0,  9}, Qt::lightGray, rootEntity);
    drawLine({-10, 0,  10}, {10, 0, 10}, Qt::lightGray, rootEntity);
    
    // text_rootEntity_rootEntity
    auto *text2D = new Qt3DExtras::QText2DEntity(/*rootEntity*/); // bug
 
    text2D->setFont(QFont("monospace"));
    text2D->setHeight(20);
    text2D->setWidth(100);
    text2D->setText("here i am");
    text2D->setColor(Qt::red);
    auto *textTransform = new Qt3DCore::QTransform(text2D);
    textTransform->setRotation(QQuaternion::fromAxisAndAngle({ 1, 0, 0 }, 90.0f));
    textTransform->setScale(0.125f);
    text2D->addComponent(textTransform);
    
    text2D->setParent(rootEntity);

    // // Torus
    // Qt3DCore::QEntity *torusEntity = new Qt3DCore::QEntity(rootEntity);
    // {
    //     // Mesh
    //     Qt3DExtras::QTorusMesh *torusMesh = new Qt3DExtras::QTorusMesh;
    //     torusMesh->setRadius(5);
    //     torusMesh->setMinorRadius(1);
    //     torusMesh->setRings(100);
    //     torusMesh->setSlices(20);

    //     // Transform
    //     Qt3DCore::QTransform *torusTransform = new Qt3DCore::QTransform;
    //     torusTransform->setScale3D(QVector3D(1.5, 1, 0.5));
    //     torusTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1, 0, 0), 45.0f));

    //     torusEntity->addComponent(torusMesh);
    //     torusEntity->addComponent(torusTransform);
    //     torusEntity->addComponent(material);
    // }

    // Sphere
    Qt3DCore::QEntity *sphereEntity = new Qt3DCore::QEntity(rootEntity);
    {
        // Mesh
        Qt3DExtras::QSphereMesh *sphereMesh = new Qt3DExtras::QSphereMesh;
        sphereMesh->setRadius(1);

        // Transform
        Qt3DCore::QTransform *sphereTransform = new Qt3DCore::QTransform;
        MyOrbitTransformController *controller = new MyOrbitTransformController(sphereTransform);
        controller->setTarget(sphereTransform);
        controller->setRadius(10.0f);

        // Animation
        QPropertyAnimation *sphereRotateTransformAnimation = new QPropertyAnimation(sphereTransform);
        sphereRotateTransformAnimation->setTargetObject(controller);
        sphereRotateTransformAnimation->setPropertyName("angle");
        sphereRotateTransformAnimation->setStartValue(QVariant::fromValue(0));
        sphereRotateTransformAnimation->setEndValue(QVariant::fromValue(360));
        sphereRotateTransformAnimation->setDuration(10000);
        sphereRotateTransformAnimation->setLoopCount(-1);
        sphereRotateTransformAnimation->start();

        sphereEntity->addComponent(sphereMesh);
        sphereEntity->addComponent(sphereTransform);
        sphereEntity->addComponent(material);
    }

    // // Plane
    // Qt3DCore::QEntity* planeEntity = new Qt3DCore::QEntity(rootEntity);
    // {
    //     Qt3DExtras::QPlaneMesh* planeMesh = new Qt3DExtras::QPlaneMesh;
    //     planeMesh->setHeight(100);
    //     planeMesh->setWidth(200);

    //     planeEntity->addComponent(planeMesh);
    //     planeEntity->addComponent(material);
    // }


    // Points
    Qt3DRender::QGeometry* geom = new Qt3DRender::QGeometry;
    // Qt3DRender::QGeometryRenderer::setPrimitiveType(Qt3DRender::QGeometryRenderer::Points);
    // Qt3DRender::QGeometryRenderer::LineStrip
    // geom->setPrimitiveType(Qt3DRender::QGeometryRenderer::Points);


    Qt3DRender::QAttribute* attrib = new Qt3DRender::QAttribute;
    attrib->setName(Qt3DRender::QAttribute::defaultPositionAttributeName());
    attrib->setVertexBaseType(Qt3DRender::QAttribute::Float);
    
    attrib->setVertexSize(3);
    attrib->setAttributeType(Qt3DRender::QAttribute::VertexAttribute);


    Qt3DRender::QBuffer* buffer = new Qt3DRender::QBuffer;

    // QByteArray

    // geom->addAttribute(attrib);

    geom->setParent(rootEntity);

    return rootEntity;
}

int main(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);

    Qt3DExtras::Qt3DWindow view;


    Qt3DCore::QEntity* scene = createScene();

    //***
    // Camera
    // 
    //          | (y)
    //          |
    //          |
    //          |_________ (x)
    //         /
    //        /
    //       / (z)
    // 
    //***


    Qt3DRender::QCamera *camera = view.camera();
    camera->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    camera->setPosition(QVector3D(20, 20, 40.0f));
    camera->setViewCenter(QVector3D(0, 0, 0));



    // For camera controls
    Qt3DExtras::QOrbitCameraController* camController = new Qt3DExtras::QOrbitCameraController(scene);
    camController->setLinearSpeed( 50.0f );
    camController->setLookSpeed( 180.0f );
    camController->setCamera(camera);

    view.setRootEntity(scene);
    view.show();

    return app.exec();

    // QApplication app(argc, argv);
    // app.setOrganizationName("");
    // app.setApplicationName("feather");
    // app.setApplicationVersion("1.0.0");

    // MyOpenGLWidget w;
    // w.show();

    // return app.exec();
}
