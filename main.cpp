#include "ftsensorapp.h"
#include <QApplication>
#include "sensorModel.h"

Qt3DCore::QEntity *createScene()
{
    QUrl data = QUrl::fromLocalFile("/home/oguz/gradSecond/img/ati/atimini40.obj");
    // Root entity
    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity;

    // Material
    Qt3DRender::QMaterial *material = new Qt3DExtras::QPhongMaterial(rootEntity);

    // Chest Entity
    Qt3DCore::QEntity *chestEntity = new Qt3DCore::QEntity(rootEntity);
    Qt3DRender::QMesh *chestMesh = new Qt3DRender::QMesh(rootEntity);
    chestMesh->setSource(data);

    chestEntity->addComponent(chestMesh);
    chestEntity->addComponent(material);

    return rootEntity;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    ftSensorApp w;
//    sensorModel s("qrc:/meshes/meshes/obj1.mesh");
    QUrl data = QUrl::fromLocalFile("/home/oguz/gradSecond/img/ati.dae");
    Qt3DExtras::Qt3DWindow view;
    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity;
    Qt3DCore::QEntity *flyingwedge = new Qt3DCore::QEntity(rootEntity);
    Qt3DExtras::QPhongMaterial *material = new Qt3DExtras::QPhongMaterial();
    material->setDiffuse(QColor(254, 254, 254));
    Qt3DRender::QMesh *flyingwedgeMesh = new Qt3DRender::QMesh(rootEntity);
    flyingwedgeMesh->setMeshName("FlyingWedge");
    flyingwedgeMesh->setSource(data);
    flyingwedge->addComponent(flyingwedgeMesh);
    flyingwedge->addComponent(material);
    Qt3DRender::QCamera *camera = view.camera();
    camera->lens()->setPerspectiveProjection(40.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    camera->setPosition(QVector3D(0, 0, 40.0f));
    camera->setViewCenter(QVector3D(0, 0, 0));
    Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(rootEntity);
    Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(lightEntity);
    light->setColor("white");
    light->setIntensity(0.8f);
    lightEntity->addComponent(light);
    Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform(lightEntity);
    lightTransform->setTranslation(QVector3D(60, 0, 40.0f));
    lightEntity->addComponent(lightTransform);
    Qt3DExtras::QOrbitCameraController *camController = new Qt3DExtras::QOrbitCameraController(rootEntity);
    camController->setCamera(camera);
    view.setRootEntity(rootEntity);
    qDebug() << flyingwedgeMesh->status();
    view.show();

//    Qt3DExtras::Qt3DWindow view;

//    Qt3DCore::QEntity *scene = createScene();

//    // Camera
//    Qt3DRender::QCamera *camera = view.camera();
//    camera->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
//    camera->setPosition(QVector3D(0, 0, 1));
//    camera->setViewCenter(QVector3D(0, 0, 0));

//    // For camera controls
//    Qt3DExtras::QOrbitCameraController *camController = new Qt3DExtras::QOrbitCameraController(scene);
//    camController->setLinearSpeed( 10.0f );
//    camController->setLookSpeed( 180.0f );
//    camController->setCamera(camera);

//    view.setRootEntity(scene);
//    view.show();

//    w.show();
    return a.exec();
}
