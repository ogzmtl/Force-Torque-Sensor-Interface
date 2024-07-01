#include "mySerialPort.h"

mySerialPort::mySerialPort(){
    listAllSerialPorts();
}
mySerialPort::~mySerialPort(){
    //intentionally empty
}
void mySerialPort::listAllSerialPorts(){

    const auto serialPortInfo = QSerialPortInfo::availablePorts();

    for(const QSerialPortInfo &portInfo : serialPortInfo)
    {
        openPorts.push_back(portInfo.systemLocation());
    }
}

std::vector<QString> mySerialPort::getOpenPorts(){
    return openPorts;
}
