#include "sensorModel.h"

sensorModel::sensorModel(QString filename)
    : filepath(filename)
{
    show3dScene();
}
sensorModel::~sensorModel(){
    //intentionally empty
}

void sensorModel::show3dScene(){
    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity;
    Qt3DRender::QMaterial *material = new Qt3DExtras::QPhongMaterial(rootEntity);
    Qt3DExtras::Qt3DWindow view;

    //my mesh
    Qt3DCore::QEntity *sensor = new Qt3DCore::QEntity(rootEntity);

    auto *sensorMesh = new Qt3DRender::QMesh();
    sensorMesh->setMeshName("ForceTorqueSensor");
    sensorMesh->setSource(QUrl::fromLocalFile("/home/oguz/gradSecond/img/ati/atimini40.obj"));
    qDebug() << sensorMesh->status();
    Qt3DRender::QCamera *camera = view.camera();
    camera->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    camera->setPosition(QVector3D(0, 0, 40.0f));
    camera->setViewCenter(QVector3D(0, 0, 0));

    sensor->addComponent(sensorMesh);
    sensor->addComponent(material);

    // For camera controls

//    QUrl data = QUrl::fromLocalFile(":/rec/img/ati/Ati Mini40.obj");
//    auto *view = new Qt3DExtras::Qt3DWindow;
//    view->defaultFrameGraph()->setClearColor(QColor(QRgb(0x1d1d4f)));
//    auto *container = QWidget::createWindowContainer(view);
//    auto screenSize = view->screen()->size();
//    container->setMinimumSize(QSize(200, 100));
//    container->setMaximumSize(screenSize);
//    auto *widget = new QWidget;
//    auto *hLayout = new QHBoxLayout(widget);
//    hLayout->addWidget(container, 1);
//    auto *input = new Qt3DInput::QInputAspect;
//    view->registerAspect(input);

//    // Root entity
//    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity;
//    Qt3DCore::QEntity *flyingwedge = new Qt3DCore::QEntity(rootEntity);

//    Qt3DExtras::QPhongMaterial *material = new Qt3DExtras::QPhongMaterial();
//    material->setDiffuse(QColor(254, 254, 254));

//    Qt3DRender::QMesh *flyingwedgeMesh = new Qt3DRender::QMesh;
//    flyingwedgeMesh->setMeshName("FlyingWedge");
//    flyingwedgeMesh->setSource(data);

//    qDebug() << flyingwedgeMesh->status();
////    flyingwedge->addComponent(flyingwedgeMesh);
////    flyingwedge->addComponent(material);
////        Qt3DExtras::QTorusMesh *m_torus = new Qt3DExtras::QTorusMesh();
////        m_torus->setRadius(1.0f);
////        m_torus->setMinorRadius(0.4f);
////        m_torus->setRings(100);
////        m_torus->setSlices(20);
//        Qt3DExtras::QPhongMaterial *torusMaterial = new Qt3DExtras::QPhongMaterial();
//        torusMaterial->setDiffuse(QColor(QRgb(0xbeb32b)));
////        flyingwedge->addComponent(m_torus);
//        flyingwedge->addComponent(flyingwedgeMesh);
//        flyingwedge->addComponent(torusMaterial);
//        flyingwedge->setEnabled(true);
//    // Camera
//    auto *cameraEntity = view->camera();
//    cameraEntity->lens()->setPerspectiveProjection(45.0f, 16.0f/7.0f, 0.1f, 1000.0f);
//    cameraEntity->setPosition(QVector3D(0, 10.0f, 20.0f));
//    cameraEntity->setUpVector(QVector3D(0, 1, 0));
//    cameraEntity->setViewCenter(QVector3D(0, 0, 0));

//    //light
//    auto *lightEntity = new Qt3DCore::QEntity(rootEntity);
//    auto *light = new Qt3DRender::QPointLight(lightEntity);
//    light->setColor("white");
//    light->setIntensity(1);
//    lightEntity->addComponent(light);
//    auto *lightTransform = new Qt3DCore::QTransform(lightEntity);
//    lightTransform->setTranslation(cameraEntity->position());
//    lightEntity->addComponent(lightTransform);

//    // For camera controls
//    auto *camController = new Qt3DExtras::QOrbitCameraController (rootEntity);
//    camController->setCamera(cameraEntity);
//    // Set root object of the scene

    Qt3DExtras::QOrbitCameraController *camController = new Qt3DExtras::QOrbitCameraController(rootEntity);
    camController->setLinearSpeed( 50.0f );
    camController->setLookSpeed( 180.0f );
    camController->setCamera(camera);
    view.setRootEntity(rootEntity);
    view.show();
//    widget->show();

//    widget->resize(1200, 800);
}
