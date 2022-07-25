#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->serialPort = new QSerialPort;

    QStringList ports;
    const auto serialPortInfos = QSerialPortInfo::availablePorts();
    int i=0;
    for(const QSerialPortInfo &serialPortInfo : serialPortInfos){
        ports.insert(i,serialPortInfo.portName());
        i++;
    }
    ui->comboBox_port->insertItems(0,ports);

    QStringList bauds;
    bauds << "9600" << "19200" << "38400" << "57600" << "115200";
    ui->comboBox_baudrate->insertItems(0,bauds);

    connect(ui->pushButton_conn,SIGNAL(clicked(bool)),this,SLOT(connectToSerial()));
    connect(this,SIGNAL(startReading()),this,SLOT(startReading()));
    //keyPressEvent(event);

    this->enableWidgets(false);



}

void MainWindow::enableWidgets(bool activate){

    ui->pushButton_frente->setEnabled(activate);
    ui->pushButton_direita->setEnabled(activate);
    ui->pushButton_esquerda->setEnabled(activate);
    ui->pushButton_re->setEnabled(activate);
    ui->pushButton_tremelique->setEnabled(activate);
    ui->pushButton_stop->setEnabled(activate);
}

void MainWindow::startReading(){

    QByteArray readData = this->serialPort->readAll();
    qDebug()<<readData;
    while(this->serialPort->waitForReadyRead(5000)){
        readData = this->serialPort->readAll();
        qDebug()<<readData;
    }
}


void MainWindow::connectToSerial(){

    if(this->serialPort->isOpen()){
        this->serialPort->close();
        ui->label_status->setText("Desconectado");
        ui->pushButton_conn->setText("Conectar");
        this->enableWidgets(false);
        return;
    }
    this->serialPort->setPortName(ui->comboBox_port->currentText());
    this->serialPort->setBaudRate(ui->comboBox_baudrate->currentText().toUInt());

    if(!this->serialPort->open(QIODevice::ReadWrite)){
        ui->label_status->setText("Falha ao conectar");
        this->enableWidgets(false);
        return;
    }
    ui->label_status->setText("Conectado");
    ui->pushButton_conn->setText("Desconectar");

    //emit startReading(true);
    enableWidgets(true);
}





MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_frente_clicked()
{
    QString val = "f";
    this->serialPort->write(val.toUtf8());
}


void MainWindow::on_pushButton_direita_clicked()
{
    QString val = "d";
    this->serialPort->write(val.toUtf8());
}


void MainWindow::on_pushButton_esquerda_clicked()
{
    QString val = "e";
    this->serialPort->write(val.toUtf8());
}


void MainWindow::on_pushButton_re_clicked()
{
    QString val = "r";
    this->serialPort->write(val.toUtf8());
}


void MainWindow::on_pushButton_tremelique_clicked()
{
    QString val = "t";
    this->serialPort->write(val.toUtf8());
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{

    switch (event->key()) {
        case Qt::Key_A:
        {
            QString val = "e";
            this->serialPort->write(val.toUtf8());
            break;
        }
        case Qt::Key_D:
        {
            QString val = "d";
            this->serialPort->write(val.toUtf8());
            break;
        }
        case Qt::Key_S:
        {
             QString val = "r";
             this->serialPort->write(val.toUtf8());
             break;
        }
        case Qt::Key_W:
        {
            QString val = "f";
            this->serialPort->write(val.toUtf8());
            break;
        }
        case Qt::Key_P:
        {
            QString val = "p";
            this->serialPort->write(val.toUtf8());
            break;
        }
        case Qt::Key_T:
        {
            QString val = "t";
            this->serialPort->write(val.toUtf8());
            break;
        }
    }
}


void MainWindow::on_pushButton_stop_clicked()
{
    QString val = "p";
    this->serialPort->write(val.toUtf8());
}

