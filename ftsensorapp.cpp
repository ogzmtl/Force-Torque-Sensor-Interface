#include "ftsensorapp.h"
#include "ui_ftsensorapp.h"
#include "mySerialPort.h"

ftSensorApp::ftSensorApp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ftSensorApp)
{
    ui->setupUi(this);
    listPorts();
//    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity();

//    // 3D modeli yükle
//    Qt3DRender::QMesh *stlMesh = new Qt3DRender::QMesh(rootEntity);
//    stlMesh->setSource(QUrl::fromLocalFile(":/rec/img/ati/Ati Mini40.STL"));

//    // 3D pencereyi oluştur
//    Qt3DExtras::Qt3DWindow *view = new Qt3DExtras::Qt3DWindow();
//    view->setRootEntity(rootEntity);

//    // Kamera kontrolcüsü ekleyin (isteğe bağlı)
//    Qt3DExtras::QFirstPersonCameraController *cameraController = new Qt3DExtras::QFirstPersonCameraController(rootEntity);
//    cameraController->setLinearSpeed(50.0f);
//    cameraController->setLookSpeed(180.0f);
//    cameraController->setCamera(view->camera());
//    cameraController->setCamera(view->camera());
//    // Kamera konumunu ayarlamak için
//    Qt3DRender::QRenderSettings *renderSettings = view->renderSettings();
//    renderSettings->setDepthTest(new Qt3DRender::QDepthTest());

//    // Widget'ı ana pencerenin merkezine yerleştir
//    setCentralWidget(QWidget::createWindowContainer(view, this));

//    // Ana pencereyi göster
//    show();
}

ftSensorApp::~ftSensorApp()
{
    delete ui;
}

void ftSensorApp::listPorts()
{
    std::unique_ptr<mySerialPort> comPorts(new mySerialPort);
    std::vector<QString> ports = comPorts->getOpenPorts();
    ui->comboBox->clear();
    if(ports.empty()) ui->comboBox->addItem("No Available Ports");
    else
    {
        for(size_t i = 0; i < ports.size(); i++)
        {
            ui->comboBox->addItem(ports[i]);
        }
    }
}


void ftSensorApp::on_refreshPortsButton_clicked()
{
    qDebug()<<"Refreshing COM ports.";
    this->listPorts();
}


void ftSensorApp::on_connectPortsButton_clicked()
{
    qDebug()<<ui->comboBox->currentText();
}

