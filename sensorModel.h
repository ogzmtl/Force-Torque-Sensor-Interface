#ifndef SENSORMODEL_H
#define SENSORMODEL_H
#include <QMainWindow>
#include <Qt3DExtras>
#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <Qt3DCore/QEntity>
#include <QMainWindow>
#include <QMesh>
#include <Qt3DRender>

class sensorModel{
public:
    sensorModel(QString filepath);
    ~sensorModel();
    void show3dScene();
private:
    QString filepath;



};
#endif // SENSORMODEL_H
