#ifndef FTSENSORAPP_H
#define FTSENSORAPP_H

#include <QMainWindow>
#include <Qt3DExtras/Qt3DWindow>
#include <Qt3DRender/QMesh>


QT_BEGIN_NAMESPACE
namespace Ui { class ftSensorApp; }
QT_END_NAMESPACE

class ftSensorApp : public QMainWindow
{
    Q_OBJECT

public:
    ftSensorApp(QWidget *parent = nullptr);
    ~ftSensorApp();
    void listPorts();

private slots:


    void on_refreshPortsButton_clicked();

    void on_connectPortsButton_clicked();

private:
    Ui::ftSensorApp *ui;
    Qt3DRender::QMesh *stlMesh;
};
#endif // FTSENSORAPP_H
