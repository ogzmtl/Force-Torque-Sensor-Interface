#ifndef MYSERIALPORT_H
#define MYSERIALPORT_H
#include <vector>
#include <iostream>
#include <QMainWindow>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <QSerialPort>
#include <QSerialPortInfo>


class mySerialPort {


public:
    mySerialPort();
    ~mySerialPort();
    std::vector<QString> getOpenPorts();
private:
    void listAllSerialPorts();
    std::vector<QString> openPorts;
};
#endif // MYSERIALPORT_H
